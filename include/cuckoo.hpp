#pragma once
#include "HashTable.hpp"
#include <cstdint>
#include <string>
#include <cmath>
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
    static uint32_t hash1(const std::string& bookName,size_t size) ;

     /**
     *  @brief Calculating the hash value for the given book using the Cuckoo Hashing based on golden ratio PHI
     *  @param bookName The book for which the hash value is to be calculated based on its title.
     *  @param size The size of the hash table to ensure the hash index will not exceed the bounds of hash table
     *  @return The hash value, which corresponds to the index in the hash table.
     */
    static uint32_t hash2(const std::string& bookName,size_t size) ;
    
};