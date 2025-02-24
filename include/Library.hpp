#include "book.hpp"
#include "Color.hpp"
#include "cuckoo.hpp"
#include "HashTable.hpp"
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <optional>
#define MISSING_FIELD ""


class Library{
    public:
        Library();//Constructor 
        //implement load from file 

        //implement search
        //implement delete
        //implement insert
        //implement sort by field


        /**
         * @brief print the held books of user
         */

        void printBooks();

        /**
         * @brief getter for books_held
         */
        std::vector<std::optional<book>> & getBooksHeld();

        /**
         * @brief overloaded std::ostream for custom printing format with books
         */
        friend std::ostream& operator<<(std::ostream& os, const std::vector<book>& books);

        /**
         * @brief getter for each HashTable
         * @param field the field to get from
         */
        HashTable& getTable(BookField field) { return this->fieldTables[field]; };
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


        /**
         * @brief load all books from a file 
         * Declared as private since im going to call the method inside the constructor
         * called Library.txt
         */
        bool loadLibrary();
};