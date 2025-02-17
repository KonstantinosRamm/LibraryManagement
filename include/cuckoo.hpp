#pragma once
#include "HashTable.hpp"
#include <string>
#include <cmath>
#include <vector>
#include <optional>
#define A 199 //random prime number
#define PHI 1.618 // golden ratio value



class cuckooHash{
    public:
     /**
     *  @brief Calculating the hash value for the given book using the Cuckoo Hashing based on a random prime A
     *  @param bookName The book for which the hash value is to be calculated based on its title.
     *  @param size The size of the hash table to ensure the hash index will not exceed the bounds of hash table
     *  @return The hash value, which corresponds to the index in the hash table.
     */
    static size_t hash1(const std::string& bookName,size_t size) ;

     /**
     *  @brief Calculating the hash value for the given book using the Cuckoo Hashing based on golden ratio PHI
     *  @param bookName The book for which the hash value is to be calculated based on its title.
     *  @param size The size of the hash table to ensure the hash index will not exceed the bounds of hash table
     *  @return The hash value, which corresponds to the index in the hash table.
     */
    static size_t hash2(const std::string& bookName,size_t size) ;

    /**
     * @brief Declaration of Cuckoo hashing
     * @param table1 hash table 1 
     * @param table2 hash table 2
     * @param book the book to be hashed
     * return true if operation suceeded or false if the tables need resize
     */
    bool insert(std::vector<std::optional <book>>& table1,std::vector<std::optional<book>>& table2,const book &Book);
    private:
    /**
     * @brief a temporary vector used to store the hashed indexes 
     */
        std::vector<size_t> hashed_indexes;
    
};