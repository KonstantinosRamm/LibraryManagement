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

class HashTable
{
    public:
    HashTable();
    /**
     * @brief Deletes a book from the hash table.
     * @param book The book to be deleted.
     * @return True if the book was found and deleted, false otherwise.

    /**
     * @brief Checks if the hash table is empty.
     * @return True if the hash table is empty, false otherwise.
     */
        bool isEmpty();

    /**
     * @brief Gets the number of books currently stored in the hash table.
     * 
     * This method returns the number of books stored in the hash table by accessing
     * the `_totalBooks` variable. It provides an efficient way to retrieve the count
     * of books without needing to iterate over the entire hash table.
     * 
     * @return The total number of books in the hash table.
     */
        size_t getNumberOfBooks();
    /**
     * @brief Calculates the load factor of the hash table.
     * The current load factor of the hash table, calculated as:
     *         _totalBooks / _numberOfSlots.
     * @return _loadFactor
     */
        double calculateLoadFactor();

    /**
     * @brief Calculates the total number of slots
     * @return _totalSlots
     */
        size_t calculateSlots();

    /**
     * @brief resizes the hash tables if load factor is bigger than 0.75
     */
    void resize();
  

    private:
        // Declaring the hash table as a vector of lists to store books with chaining for collision handling.
        // we have 2 hash tables so we can apply the cuckoo hashing
        // It is a more simplified version of hash table .since it doesnt use linked lists for chaining
        // the reason behind that is because cuckoo hashing ensures that no chaining occurs so it would 
        //be over kill to add linked lists inside vector
        //std::optional added for memory safety
        std::vector<std::optional<book>> table1;
        std::vector<std::optional<book>> table2;
        size_t _totalBooks;
        double _loadFactor;
        size_t _totalSlots;



};