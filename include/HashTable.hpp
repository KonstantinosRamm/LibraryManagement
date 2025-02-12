#pragma once
#define SLOTS 11
#include "book.hpp"
#include <list>
#include <vector>
#include <array>

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
     * @brief Inserts a book into the hash table.
     * @param book The book to be inserted.
     * @return True if the book was successfully inserted, false otherwise.
     */
        bool insertBook(const book &Book);

    /**
     * @brief Deletes a book from the hash table.
     * @param book The book to be deleted.
     * @return True if the book was found and deleted, false otherwise.
     */
        bool deleteBook(const book &Book);

    /**
     * @brief Searches for a book in the hash table.
     * @param book The book to search for.
     * @return True if the book was found, false otherwise.
     */
        bool searchBook(const book &Book);

    /**
     * @brief Updates the information of an existing book in the hash table.
     * @param book The book with updated details.
     * @return True if the update was successful, false otherwise.
     */
        bool updateBook(const book &Book);

    /**
     * @brief Prints all books stored in the hash table.
     */
        void printBooks();

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
     * @return The current load factor of the hash table, calculated as:
     *         _totalBooks / _numberOfSlots.
     */
        float calculateLoadFactor();

    /**
     *  @brief Calculating the hash value for the given book using the Cuckoo Hashing
     *  @param book The book for which the hash value is to be calculated.
     * 
     *  @return The hash value, which corresponds to the index in the hash table.
     */
        size_t hash(const book& book);

    private:
        // Declaring the hash table as a vector of lists to store books with chaining for collision handling.
        std::vector<std::list<book>> table;
        size_t _totalBooks = 0;
        size_t _numberOfSlots = 0;
        double loadFactor = 0;



};