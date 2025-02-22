#pragma once
#include <string>
#define numberOfFields 6 // number of fields used currently for each book


/**
 * @struct book
 * @brief Represents a book with its attributes.
 * 
 * This struct holds the basic attributes of a book, such as title, author, publisher, genre, 
 * year of publication, and ISBN number. These fields are all stored as strings.
 */
struct book
{
    /**
     * @brief The title of the book.
     * 
     * This is the name or title of the book.
     */
    std::string Title;

    /**
     * @brief The author of the book.
     * 
     * This is the author(s) of the book.
     */
    std::string Author;

    /**
     * @brief The publisher of the book.
     * 
     * This is the publisher of the book.
     */
    std::string Publisher;

    /**
     * @brief The genre of the book.
     * 
     * This is the genre or category to which the book belongs.
     */
    std::string Genre;

    /**
     * @brief The year the book was published.
     * 
     * This is the publication year of the book, stored as a string.
     */
    std::string Year;

    /**
     * @brief The ISBN of the book.
     * 
     * This is the International Standard Book Number (ISBN) of the book.
     */
    std::string ISBN;
};

    /**
     * @brief BookField Enum is used for determining which field we are going to use for hashing and
     * the hash table at which it will be stored
     */
enum BookField {
    Title = 0,
    Author,
    Publisher,
    Year,
    Genre,
    ISBN,
};
