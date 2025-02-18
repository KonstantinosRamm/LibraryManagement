#include "book.hpp"
#include "Color.hpp"
#include "cuckoo.hpp"
#include "HashTable.hpp"
#include <array>




class Library{
    public:

        //implement search
        //implement delete
        //implement insert
        //implement sort by field
        
    private:
        /**
         * @brief an array of hash tables based on the number of fields of the book defined in book.hpp
         */
        std::array<HashTable, numberOfFields> fieldTables;
        /**
         * @brief a vector with the books held to simplify the process of printing all the books currently held
         * without messing with the multiple hash tables
         */
        std::vector<book> books_held;
};