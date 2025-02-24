#include "HashTable.hpp"
#include "Color.hpp"
#include <iostream>




//Constructor
HashTable::HashTable()
{

    this->table1.resize(2);
    this->table2.resize(2);
}




void HashTable::resize()
{
    this->table1.resize(2*this->table1.size());
    this->table2.resize(2*this->table2.size());
}


//setters and getters
std::vector<size_t>& HashTable::getTable1() {return this->table1;}

std::vector<size_t>& HashTable::getTable2() {return this->table2;}




