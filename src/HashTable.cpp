#include "HashTable.hpp"
#include "Color.hpp"
#include <iostream>



//Constructor
HashTable::HashTable()
{

    for(int i = 0; i < tablesSize; i++)
    {
        this->tables[i].resize(2, isEmpty);
    }
    this->visited_table1.resize(2, isEmpty);
    this->visited_table2.resize(2, isEmpty);
    this->table_id = false;
    
}




void HashTable::resizeCuckoo()
{
    for(int i = 0; i < tablesSize; i++)
    {
        this->tables[i].resize(2*this->tables[i].size(), isEmpty);
    }
}



size_t HashTable::hash1(const std::string& str, size_t table_size)
{
    if (str.empty())
    {
        std::cerr << "Error: Empty string passed to hash1 function." << std::endl;
        return 0;
    }
    size_t key = 0;
    size_t stringSize = str.size();
    // iterate over the string and calculate its alphanumeric value
    for (int i = 0; i < stringSize; i++)
    {
        key += str[i];
    }

    return static_cast<size_t>(key % A) % table_size;
}

size_t HashTable::hash2(const std::string& str,size_t size)
{
    if (str.empty())
    {
        std::cerr << "Error: Empty string passed to hash1 function." << std::endl;
        return 0;
    }
    size_t hash = 0;
    int prime = 31;
    for(char c: str)
    {
        hash = hash * prime + c;
    }

    return hash % size;
}





bool HashTable::cuckoo(const std::string& key) {
    std::array<size_t, tablesSize> indexes;
    indexes[0] = hash1(key, this->tables[0].size());
    indexes[1] = hash2(key, this->tables[1].size());

    std::cout << "Indexes: [" << indexes[0] << ", " << indexes[1] << "]\n";

    // Detect cycle by checking visited indices in both tables
    for (size_t i = 0; i < visited_table1.size(); i++) {
        if (visited_table1[i] == indexes[0] && visited_table2[i] == indexes[1]) {
            resizeCuckoo();
            return cuckoo(key);
        }
    }

    // Track visited indices
    visited_table1.push_back(indexes[0]);
    visited_table2.push_back(indexes[1]);

    // Check for an empty slot
    for (size_t i = 0; i < tablesSize; i++) {
        if (this->tables[i][indexes[i]] == isEmpty) {
            this->tables[i][indexes[i]] = this->books.size() - 1;
            visited_table1.clear(); // Reset after successful insertion
            visited_table2.clear();
            return true;
        }
    }

    // Eviction: Get evicted key, swap, and reinsert
    size_t evictedIndex = this->tables[table_id][indexes[table_id]];
    std::string evictedKey = this->books[evictedIndex];

    this->tables[table_id][indexes[table_id]] = this->books.size() - 1; // Place new key
    table_id = !table_id; // Toggle table

    return cuckoo(evictedKey); // Reinsert evicted key
}


void HashTable::insert(const std::string& str)
{
    this->books.push_back(str);
}



