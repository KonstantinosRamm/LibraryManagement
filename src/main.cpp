#include "HashTable.hpp"
#include "book.hpp"
#include <iostream>
#include <vector>


 
int main(void){
    std::vector<book> arr;
    std::vector<book> heldBooks;
    book test = {{"1","2","3","4","5","6"}};
    book test2 = {{"2","2","3","4","5","6"}};



    for(int i = 0; i < 100; i++)
    {
        arr.push_back(test);
        arr.push_back(test2);
        
    }
    HashTable Hashtest;

    for(int i = 0; i < arr.size(); i++)
    {
        if(Hashtest.cuckoo(arr[i], 0))
        {
            heldBooks.push_back(arr[i]);
        }
    }
return 0;
}

