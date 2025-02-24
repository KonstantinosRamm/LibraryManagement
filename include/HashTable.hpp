#pragma once
#include "book.hpp"
#include <list>
#include <vector>
#include <array>
#include <optional>

/**
 * @class HashTable
 * @brief A hash table data structure for storing and managing books.
 * 
 * This Class provides CRUD operations for managing books using a hash table.
 */

 //Library class is defined in Library.hpp . Just redefined here so we can set it as a friend to HashTable
 class Library;


class HashTable
{
    public:
    /**
     * @brief set Library as friend for easier acess to private members of Hash table
     * (to avoid creating multiple setters and getters)
     */
    
    friend class Library;
    HashTable();
    /**
     * @brief Checks if the hash table is empty.
     * @return True if the hash table is empty, false otherwise.
     */
        bool isEmpty();
    /**
     * @brief resizes the hash tables if load factor is bigger than 0.75 
     * 
     */
        void resize();

    

    /**
     * @brief setter for table1
     * @param t1 the vector we want to assigned in table 1 
     */

    void setTable1(std::vector<book> &t1) ;

    /**
     * @brief setter for table2
     * @param t2 the vector we want to assigned in table 1 
     * 
     */
    void setTable2(std::vector<book> &t2) ;


    /**
     * @brief getter for table1 
    */

    std::vector<book>& getTable1();

    /**
     * @brief getter for table2
    */
    std::vector<book>& getTable2();

    private:
        // Declaring the hash table as a vector of lists to store books with chaining for collision handling.
        // we have 2 hash tables so we can apply the cuckoo hashing
        // It is a more simplified version of hash table .since it doesnt use linked lists for chaining
        // the reason behind that is because cuckoo hashing ensures that no chaining occurs so it would 
        //be over kill to add linked lists inside vector
        //std::optional added for memory safety
        std::vector<book> table1;
        std::vector<book> table2;

};