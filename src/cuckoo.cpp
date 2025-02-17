#include "cuckoo.hpp"

std::vector<size_t> cuckooHash::visited_table1;
std::vector<size_t> cuckooHash::visited_table2;

size_t cuckooHash::hash1(const std::string& bookName,size_t table_size)
{
    size_t key = 0;
    size_t stringSize = bookName.size();
    //iterate over the string and calculate its alphanumeric value
    for(int i = 0; i < stringSize; i++)
    {
        key += bookName[i];
    }

    return static_cast<size_t>(key % A) % table_size;
}


size_t cuckooHash::hash2(const std::string& bookName,size_t table_size)
{
    size_t key = 0;
    size_t stringSize = bookName.size();
    //iterate over the string and calculate its alphanumeric value
    for(int i = 0; i < stringSize; i++)
    {
        key += bookName[i];
    }

    //multiplication by golden ratio
    return static_cast<size_t>(table_size * (key * PHI - floor(key * PHI))) % table_size;

}


bool cuckooHash::insert(std::vector<std::optional<book>>& table1, std::vector<std::optional<book>>& table2, const book &Book)
{
    // Hash books using both functions
    size_t index1 = hash1(Book.Title, table1.size());
    size_t index2 = hash2(Book.Title, table2.size());

    // Base case: check for cycle in table1 or table2
    for (int i = 0; i < cuckooHash::visited_table1.size(); i++)
    {
        if (cuckooHash::visited_table1[i] == index1)
        {
            cuckooHash::visited_table1.clear();
            cuckooHash::visited_table2.clear();
            return false; // Cycle detected in table1
        }
    }

    for (int i = 0; i < cuckooHash::visited_table2.size(); i++)
    {
        if (cuckooHash::visited_table2[i] == index2)
        {
            cuckooHash::visited_table1.clear();
            cuckooHash::visited_table2.clear();
            return false; // Cycle detected in table2
        }
    }

    // No cycle detected, so add the current indexes to the visited list
    cuckooHash::visited_table1.push_back(index1);
    cuckooHash::visited_table2.push_back(index2);

    /*
        Now we proceed to insert the book into table1 at index1
    */
    if (!table1[index1].has_value())
    {
        table1[index1] = Book;
        // Successful insertion, clear visited indices
        cuckooHash::visited_table1.clear();
        cuckooHash::visited_table2.clear();
        return true;
    }

    // Table1 is occupied, evict the book and insert it into table2
    book evictedBook = table1[index1].value();
    table1[index1] = Book;

    // Try to insert the evicted book into table2
    if (!table2[index2].has_value())
    {
        table2[index2] = evictedBook;
        // Successful insertion, clear visited indices
        cuckooHash::visited_table1.clear();
        cuckooHash::visited_table2.clear();
        return true;
    }

    // If table2 is also occupied, evict the book from table2 and continue recursion
    book evictedBookFromTable2 = table2[index2].value();
    table2[index2] = evictedBook;

    // Recursively try to insert the evicted book into table1
    bool result = insert(table1, table2, evictedBookFromTable2);

    // Clear the visited indices only when the insertion is successful
    if (result)
    {
        cuckooHash::visited_table1.clear();
        cuckooHash::visited_table2.clear();
    }

    return result;
}

