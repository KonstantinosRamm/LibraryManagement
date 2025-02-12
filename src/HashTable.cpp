#include "HashTable.hpp"
#include "Color.hpp"
#include <iostream>



//Constructor
HashTable::HashTable()
{
    this->loadFactor = 0;
    this->_numberOfSlots = 0;
    this->_totalBooks = 0;
}


bool HashTable::isEmpty()
{
    return this->_totalBooks == 0;
}


void HashTable::printBooks()
{
    if(isEmpty())
    {
        std::cout << COLOR_INFO << "[INFO] you have no books" << RESET << std::endl;
        return;
    }

    size_t sizeOfTable = this->table.size();
    //iterate over the table and acess each list contents
    for(int i = 0; i < sizeOfTable; i++)
    {
        for(std::list<book>::iterator it = this->table[i].begin(); it != this->table[i].end(); ++it)
        {
            /*TO DO OVERLOAD std::ostream to customize the format of printing the book*/
            //std::cout << it;
        }
    }
}
