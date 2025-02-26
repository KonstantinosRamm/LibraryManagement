#include "HashTable.hpp"
#include "Color.hpp"
#include <iostream>



//Constructor
HashTable::HashTable()
{
    book empty;
    //dynamically create empty book to insert in the tables
    for(int i = 0; i < fields; i++)
    {
        empty.arr[i] = isEmpty;
    }
    //resize the tables with empty books
    for(int i = 0; i < tablesSize; i++)
    {
        this->tables[i].resize(2, empty);
    }
    //resize visited tables with no value
    this->visited_table1.resize(2, noValue);
    this->visited_table2.resize(2, noValue);
    this->table_id = false;
    
}




void HashTable::resizeCuckoo()
{   book empty = {"","","","","",""};
    for(int i = 0; i < tablesSize; i++)
    {
        this->tables[i].resize(2*this->tables[i].size(), empty);
    }
}

uint32_t HashTable::MurmurHash3(const void* key, int len, uint32_t seed)
{
    const uint8_t* data = (const uint8_t*)key;
    const int nblocks = len / 4;
    uint32_t h1 = seed;

    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    // Body
    const uint32_t* blocks = (const uint32_t*)(data + nblocks * 4);
    for (int i = -nblocks; i; i++)
    {
        uint32_t k1 = blocks[i];

        k1 *= c1;
        k1 = (k1 << 15) | (k1 >> 17);
        k1 *= c2;

        h1 ^= k1;
        h1 = (h1 << 13) | (h1 >> 19);
        h1 = h1 * 5 + 0xe6546b64;
    }

    // Tail
    const uint8_t* tail = (const uint8_t*)(data + nblocks * 4);
    uint32_t k1 = 0;

    switch (len & 3)
    {
    case 3:
        k1 ^= tail[2] << 16;
    case 2:
        k1 ^= tail[1] << 8;
    case 1:
        k1 ^= tail[0];
        k1 *= c1;
        k1 = (k1 << 15) | (k1 >> 17);
        k1 *= c2;
        h1 ^= k1;
    };

    // Finalization
    h1 ^= len;
    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;

    return h1;
}

size_t HashTable::hash1(const std::string& str, size_t table_size)
{
    if (str.empty())
    {
        std::cerr << "Error: Empty string passed to hash1 function." << std::endl;
        return 0;
    }

    uint32_t hash = MurmurHash3(str.c_str(), str.size(), 0x9747b28c); // Seed with a constant
    return hash % table_size;
}

size_t HashTable::hash2(const std::string& str, size_t table_size)
{
    if (str.empty())
    {
        std::cerr << "Error: Empty string passed to hash2 function." << std::endl;
        return 0;
    }

    uint32_t hash = MurmurHash3(str.c_str(), str.size(), 0x5bd1e995); // Seed with a different constant
    return hash % table_size;
}





bool HashTable::cuckoo(const book& key, size_t field)
{

    // Check if the key is empty and not insert it 
    if (key.arr[field].empty())
    {
        return false;
    }

    //indexes for the two tables
    std::array<size_t, tablesSize> indexes;
    indexes[0] = hash1(key.arr[field], this->tables[0].size());
    indexes[1] = hash2(key.arr[field], this->tables[1].size());

    // Check if the key already exists in the hash table based on the specific field
    for (size_t i = 0; i < tablesSize; i++)
    {
        if (this->tables[i][indexes[i]].arr[field] == key.arr[field])
        {
            return false; // Key already exists, skip insertion
        }
    }
    
    // Base case check for cycle
    for (size_t i = 0; i < visited_table1.size(); i++)
    {
        // Cycle found
        if (visited_table1[i] == indexes[0] && visited_table2[i] == indexes[1])
        {
            resizeCuckoo();
            return cuckoo(key, field);
        }
    }

    visited_table1.push_back(indexes[0]);
    visited_table2.push_back(indexes[1]);

    // Check if any slot is empty
        for (size_t i = 0; i < tablesSize; i++)
        {
            if (indexes[i] >= this->tables[i].size())
            {
                return false;
            }

            if (this->tables[i][indexes[i]].arr[field] == isEmpty)
            {
                // Insert the key in the empty slot
                this->tables[i][indexes[i]] = key;
                // Clear visited tables for the next cuckoo hash operation
                this->visited_table1.clear();
                this->visited_table2.clear();
                return true;
            }
        }

    // If no empty slot found, evict the indexes until we find the correct slot to place them
    book evictedBook = this->tables[table_id][indexes[table_id]];
    this->tables[table_id][indexes[table_id]] = key; // Place new key
    table_id = !table_id; // Toggle table_id for the next recursion

    // Recursive call with the new evicted key
    return cuckoo(evictedBook, field);
}





