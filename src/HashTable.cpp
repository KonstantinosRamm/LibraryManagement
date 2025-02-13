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

    size_t sizeOfTable1 = this->table1.size();
    size_t sizeOfTable2 = this->table2.size();
    //iterate over the table1 and acess each list contents
    for(int i = 0; i < sizeOfTable1; i++)
    {
        for(std::list<book>::iterator it = this->table1[i].begin(); it != this->table1[i].end(); it++)
        {
            /*TO DO OVERLOAD std::ostream to customize the format of printing the book*/
            //std::cout << it;
        }
    }

    //iterator over table2 and do the same process as above
    for(int i = 0; i < sizeOfTable2; i++)
    {
        for(std::list<book>::iterator it = this->table2[i].begin(); it != this->table2[i].end(); it++)
        {
            /*TO DO OVERLOAD std::ostream to customize the format of printing the book*/
            //std::cout << it;
        }
    }
}
