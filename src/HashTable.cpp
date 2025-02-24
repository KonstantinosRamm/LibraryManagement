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

void HashTable::setTable1(std::vector<book> &t1) { this->table1 = t1;}

void HashTable::setTable2(std::vector<book> &t2) { this->table2 = t2;}

std::vector<book>& HashTable::getTable1() {return this->table1;}

std::vector<book>& HashTable::getTable2() {return this->table2;}




