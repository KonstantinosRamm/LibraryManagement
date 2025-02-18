#include "HashTable.hpp"
#include "Color.hpp"
#include <iostream>




//Constructor
HashTable::HashTable()
{

        this->_loadFactor = 0;
        this->_totalBooks = 0;
        this->_totalSlots = 0;
        this->table1.resize(2);
        this->table2.resize(2);
}


bool HashTable::isEmpty()
{
    return this->_totalBooks == 0;
}

double HashTable::calculateLoadFactor()
{
        //ensure not to division with 0

    if(this->_totalSlots == 0)
    {
        this->_loadFactor = 0;

    }
    else
    {
        this->_loadFactor = static_cast<double>(this->_totalBooks)/this->_totalSlots;
    
    }

    return this->_loadFactor;
}


size_t HashTable::calculateSlots()
{
    this->_totalSlots = this->table1.size() + this->table2.size();
    return this->_totalSlots;
}

void HashTable::resize()
{
    if (calculateLoadFactor() > 0.75)
    {
        this->table1.resize(2*this->table1.size());
        this->table2.resize(2*this->table2.size());
        //update load factor
        calculateLoadFactor();
        calculateSlots();
    }
}



