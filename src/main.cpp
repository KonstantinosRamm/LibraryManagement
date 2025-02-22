#include "book.hpp"
#include "HashTable.hpp"
#include "cuckoo.hpp"
#include "Library.hpp"



 
int main(void) {
    Library test;
    test.printBooks();
    //get all books and hash them to the hash them using cuckoo
    std::vector<std::optional<book>> & books = test.getBooksHeld();

    for(size_t i = 0; i < books.size(); i++)
    {
        //more checks to check if the book inserted is empty 
        if (!books[i].has_value()) {
            continue; // Skip empty entries
        }
        

        //get book from books and extract it as const since cuckooHash::insert expects const&book
        const book& currentBook = books[i].value(); // Extract the book safely
        //insert all books based on all fields
        for(int  field = 0; field < numberOfFields; field++)
        {
            //static cast field from integer to Book Field
            BookField bookField = static_cast<BookField>(field);
            cuckooHash::insert(test.getTable(bookField),currentBook,bookField);
        }
    }


    return 0;
}

