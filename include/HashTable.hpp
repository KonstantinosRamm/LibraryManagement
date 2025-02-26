#pragma once
#include <list>
#include <vector>
#include <array>
#include <optional>
#include <cmath>
#include <string>
#include <limits>
#include <cstdint>
#include <book.hpp>
#define A 10007 //random prime number
#define PHI 1.618 // golden ratio value
#define isEmpty "" //string that indicates empty value
#define noValue std::numeric_limits<size_t>::max() //value that indicates no value
#define tablesSize 2 // number of tables used in cuckoo hashing

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










    /*
    
    
    
    
    
                                        HASH FUNCTIONS AND CUCKOO HASHING
                                        
                                        
                                        
                                        
                                        
    */












    /**
     * @brief Declaration of Cuckoo hashing. It uses the internal hash tables (2 tables) store the index and resizes in case of a cycle occurs
     * @param key string to be hashed
     * @param table_id determine where we are cuckooing table1 or table2
     * @param books the book to be stored
     * @param field the field of the vook to be hashed
     * return true if operation suceeded or false if the tables need resize
     */
    bool cuckoo(const book& key,size_t field);
















    private:
    /**
     * @brief array of 2 vectors (tables) used in cuckoo hashing
     */
        std::array<std::vector<book>, tablesSize> tables;



    /**
    * @brief a temporary vector1 used to store the hashed indexes 
    */
    std::vector<size_t> visited_table1;
    /**
    * @brief a temporary vector2 used to store the hashed indexes 
    */
    std::vector<size_t> visited_table2;





    /**
     * @brief if cycle found during cuckoo hash
     * 
     */
    void resizeCuckoo();

    /**
     * @brief table id used on cuckoo hash and indicates which is the current table to be used for cuckoo
     */
    bool table_id;


     /**
     *  @brief Calculating the hash value for the given book using the Cuckoo Hashing based on a random prime A
     *  @param str The str for which the hash value is to be calculated
     *  @param size The size of the hash table to ensure the hash index will not exceed the bounds of hash table
     *  @return The hash value, which corresponds to the index in the hash table.
     */
    size_t hash1(const std::string& str,size_t size) ;

     /**
     *  @brief Calculating the hash value for the given book using the Cuckoo Hashing based on golden ratio PHI
     *  @param str The str for which the hash value is to be
     *  @param size The size of the hash table to ensure the hash index will not exceed the bounds of hash table
     *  @return The hash value, which corresponds to the index in the hash table.
     */
    size_t hash2(const std::string& str,size_t size);

     /**
     * @brief Computes the MurmurHash3 hash value for the given key.
     * 
     * MurmurHash3 is a non-cryptographic hash function suitable for general hash-based lookup.
     * It is known for its good distribution and performance.
     * 
     * @param key The key to be hashed.
     * @param len The length of the key in bytes.
     * @param seed A seed value for the hash function to ensure different hash values for the same key.
     * @return The computed hash value as a 32-bit unsigned integer.
     */
    uint32_t MurmurHash3(const void* key, int len, uint32_t seed);


    





};