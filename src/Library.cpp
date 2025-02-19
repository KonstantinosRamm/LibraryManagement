#include "Library.hpp"


Library::Library()
{
    loadLibrary();
}

bool Library::loadLibrary()
{
    std::ifstream file("Library.txt");

    if (!file)
    {
        std::cerr << COLOR_ERROR << "[ERROR] Could not open Library " << RESET << std::endl;
        return false; // Indicate that an error occurred during the file opening
    }

    std::string line;
    
    while (std::getline(file, line)) // Read the first line (Author)
    {
        book Book;
        Book.Author = line; // Assign the first line to Author

        // Read the remaining fields, checking if they exist
        if (!std::getline(file, Book.Title))     Book.Title = MISSING_FIELD;
        if (!std::getline(file, Book.Publisher)) Book.Publisher = MISSING_FIELD;
        if (!std::getline(file, Book.Genre))     Book.Genre = MISSING_FIELD;
        if (!std::getline(file, Book.Year))      Book.Year = MISSING_FIELD;
        if (!std::getline(file, Book.ISBN))      Book.ISBN = MISSING_FIELD;

        this->books_held.push_back(Book);
    }
    std::cout << SUCESS_COLOR << "[SUCESS] reading all books!" << RESET << std::endl;
    file.close();
    return true; // Indicate success
}


std::ostream& operator<<(std::ostream& os, const std::vector<book>& books)
{
    os << COLOR_INFO << "\t\tAuthor\t\tTitle\t\tPublisher\t\tGenre\t\tYear\t\tISBN" << RESET << std::endl;
    size_t ctr = 1;
    for(book current : books)
    {
        os << COLOR_INFO << ctr << RESET;
        os << SUCESS_COLOR ;
        os << "\t\t" << current.Author ;
        os << "\t\t" << current.Title ;
        os << "\t\t" << current.Publisher ;
        os << "\t\t" << current.Genre ;
        os << "\t\t" << current.Year ;
        os << "\t\t" << current.ISBN ;
        os << std::endl;
        ++ctr;

    }
    os << RESET << std::endl;

    return os;

}


void Library::printBooks()
{
    std::cout << this->books_held;
}
