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

    std::vector<size_t>& getTable1();

    /**
     * @brief getter for table2
    */
    std::vector<size_t>& getTable2();

    private:


    /**
     * @brief table 1 used for cuckoo hashing .stores only the index of the vector where the string is 
     */
        std::vector<size_t> table1;
    /**
     * @brief table 2 used for cuckoo hashing .stores only the index of the vector where the string is 
     */
        std::vector<size_t> table2;

};