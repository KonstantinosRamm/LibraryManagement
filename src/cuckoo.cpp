#include "cuckoo.hpp"

std::vector<size_t> cuckooHash::visited_table1;
std::vector<size_t> cuckooHash::visited_table2;

size_t cuckooHash::hash1(const std::string& str,size_t table_size)
{
    size_t key = 0;
    size_t stringSize = str.size();
    //iterate over the string and calculate its alphanumeric value
    for(int i = 0; i < stringSize; i++)
    {
        key += str[i];
    }

    return static_cast<size_t>(key % A) % table_size;
}


size_t cuckooHash::hash2(const std::string& str,size_t table_size)
{
    size_t key = 0;
    size_t stringSize = str.size();
    //iterate over the string and calculate its alphanumeric value
    for(int i = 0; i < stringSize; i++)
    {
        key += str[i];
    }

    //multiplication by golden ratio
    return static_cast<size_t>(table_size * (key * PHI - floor(key * PHI))) % table_size;

}


bool cuckooHash::insert(HashTable &library, const book &Book, const BookField field)
{
    size_t index1, index2;
    std::vector<std::optional<book>>& table1 = library.getTable1();
    std::vector<std::optional<book>>& table2 = library.getTable2();

    // Select the appropriate field value to hash
    std::string fieldValue;
    if (field == ISBN) {
        fieldValue = Book.ISBN;
    } else if (field == Title) {
        fieldValue = Book.Title;
    } else if (field == Author) {
        fieldValue = Book.Author;
    } else if (field == Publisher) {
        fieldValue = Book.Publisher;
    } else if (field == Year) {
        fieldValue = Book.Year;
    } else if (field == Genre) {
        fieldValue = Book.Genre;
    } else {
        std::cerr << COLOR_ERROR << "[ERROR] Unknown field: " << field << RESET << std::endl;
        return false;  // Invalid field, return false
    }




    //just one more check to see if the field is empty to avoid inserting it 
    if(fieldValue.empty())
    {
        std::cerr << COLOR_INFO << "[INFO] Missing Field will be skipped" << RESET << std::endl;
        //break the method here and return true to not trigger a resize of the table as it would happen by returning false
        return true;
    }

    // Hash books using the selected field value
    index1 = hash1(fieldValue, table1.size());
    index2 = hash2(fieldValue, table2.size());

    for (int i = 0; i < cuckooHash::visited_table1.size(); i++) {
        if (cuckooHash::visited_table1[i] == index1) {
            cuckooHash::visited_table1.clear();
            cuckooHash::visited_table2.clear();
            //resize tables and continue cuckoo hashing
            /* Apply resize  */
            return false; // Cycle detected in table1
        }
    }

    for (int i = 0; i < cuckooHash::visited_table2.size(); i++) {
        if (cuckooHash::visited_table2[i] == index2) {
            cuckooHash::visited_table1.clear();
            cuckooHash::visited_table2.clear();
            return false; // Cycle detected in table2
        }
    }

    // No cycle detected, so add the current indexes to the visited list
    cuckooHash::visited_table1.push_back(index1);
    cuckooHash::visited_table2.push_back(index2);

    // Proceed to insert the book into table1 at index1
    if (!table1[index1].has_value()) {
        table1[index1] = Book;
        cuckooHash::visited_table1.clear();
        cuckooHash::visited_table2.clear();
        return true;
    }

    // Table1 is occupied, evict the book and insert it into table2
    book evictedBook = table1[index1].value();
    table1[index1] = Book;

    // Try to insert the evicted book into table2
    if (!table2[index2].has_value()) {
        table2[index2] = evictedBook;
        cuckooHash::visited_table1.clear();
        cuckooHash::visited_table2.clear();
        return true;
    }

    // If table2 is also occupied, evict the book from table2 and continue recursion
    book evictedBookFromTable2 = table2[index2].value();
    table2[index2] = evictedBook;

    // Recursively try to insert the evicted book into table1
    bool result = insert(library, evictedBookFromTable2, field);

    // Clear the visited indices only when the insertion is successful
    if (result) {
        cuckooHash::visited_table1.clear();
        cuckooHash::visited_table2.clear();
    }

    return result;
}
