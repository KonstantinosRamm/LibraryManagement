#pragma once
#include <string>
#include <array>
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
    std::array<std::string, numberOfFields> fields;
};


enum BookField {
    ISBN = 0,
    Title,
    Author,
    Publisher,
    Year,
    Genre
    
};
