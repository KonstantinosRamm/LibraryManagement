#include "book.hpp"
#include "HashTable.hpp"
#include "cuckoo.hpp"
#include <iostream>


int main(void)
{   
    HashTable test;
    double load = test.calculateLoadFactor();
    std::cout << "load factor = " << load << std::endl;
    return 0;
}
