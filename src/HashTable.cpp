#include "HashTable.hpp"
#include "Color.hpp"
#include <iostream>




//Constructor
HashTable::HashTable()
{
    this->_loadFactor = 0;
    this->_totalBooks = 0;
    this->_totalSlots = 0;
}


bool HashTable::isEmpty()
{
    return this->_totalBooks;
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
        
            /*TO DO OVERLOAD std::ostream to customize the format of printing the book*/
            //std::cout << table1[i];
        
    }

    //iterator over table2 and do the same process as above
    for(int i = 0; i < sizeOfTable2; i++)
    {

            /*TO DO OVERLOAD std::ostream to customize the format of printing the book*/
            //std::cout << table2[i];
    }
}


void HashTable::calculateLoadFactor()
{

    this->_loadFactor = static_cast<double>(this->_totalBooks)/this->_totalSlots;
    
}


size_t HashTable::calculateSlots()
{
    this->_totalSlots = this->table1.size() + this->table2.size();
    return this->_totalSlots;
}
