#pragma once
#define SLOTS 11
#include "book.hpp"
#include <list>
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
    
    private:
        std::array<std::list<book>, SLOTS> table;
        size_t _totalBooks = 0;

};