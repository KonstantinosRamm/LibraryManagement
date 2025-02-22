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


std::ostream& operator<<(std::ostream& os, const std::vector<std::optional<book>>& books)
{
    os << COLOR_INFO << "\t\t\t\tAuthor\t\t\t\tTitle\t\t\t\tPublisher\t\t\t\tGenre\t\t\t\tYear\t\t\t\tISBN" << RESET << std::endl;
    
    for(size_t i = 0; i < books.size(); i++)
    {
        //since we have std::optional type we have to check if the book has values in it (just to be pedantic)
        if(books[i].has_value())
        {
            //declared as const since value() method will return a const object
            const book& currentBook = books[i].value();
            os << COLOR_INFO << i + 1 << RESET;
            os << SUCESS_COLOR ;
            os << "\t\t\t\t" << currentBook.Author ;
            os << "\t\t\t\t" << currentBook.Title ;
            os << "\t\t\t\t" << currentBook.Publisher ;
            os << "\t\t\t\t" << currentBook.Genre ;
            os << "\t\t\t\t" << currentBook.Year ;
            os << "\t\t\t\t" << currentBook.ISBN ;
            os << std::endl;
        }


    }
    os << RESET << std::endl;

    return os;

}


void Library::printBooks()
{
    std::cout << this->books_held;
}
