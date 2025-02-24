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
    
    while (true) // Read the first line (Author)
    {
        book Book;
        // Read all fields
        for(int i = 0; i < numberOfFields; i++){
        
            std::getline(file,Book.fields[i]);
            //exit if we reach the end of file 
            if (file.eof()){
                //ensure to add the book if it hash at least one field completed
                if (i > 0) {
                    this->books_held.push_back(Book); // Push the last book (if it has at least one field)
                }
                std::cout << SUCESS_COLOR << "[SUCESS] reading all books!" << RESET << std::endl;
                file.close();
                return true;
            }
        }
    //push book to vector 
        this->books_held.push_back(Book);

    }

    return true; // Indicate success
}


std::ostream& operator<<(std::ostream& os, const std::vector<book>& books)
{
    os << COLOR_INFO << "----------------------------------------------------------------------------------------------------------------------" << RESET << std::endl;

    
    for(size_t i = 0; i < books.size(); i++)
    {
        os << COLOR_INFO << i + 1 << RESET;
        os << SUCESS_COLOR ;

        //make a loop and print all fields
        for(int j = 0; j < numberOfFields; j++)
        {
            os << "\t" << books[i].fields[j];
        }
        os << std::endl;
    }

    os << RESET << std::endl;

    return os;

}



void Library::printBooks()
{
    std::cout << books_held;
}

