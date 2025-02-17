#include "cuckoo.hpp"


size_t cuckooHash::hash1(const std::string& bookName,size_t table_size)
{
    size_t key = 0;
    size_t stringSize = bookName.size();
    //iterate over the string and calculate its alphanumeric value
    for(int i = 0; i < stringSize; i++)
    {
        key += bookName[i];
    }

    return static_cast<u_int32_t>(key % A) % table_size;
}


size_t cuckooHash::hash2(const std::string& bookName,size_t table_size)
{
    size_t key = 0;
    size_t stringSize = bookName.size();
    //iterate over the string and calculate its alphanumeric value
    for(int i = 0; i < stringSize; i++)
    {
        key += bookName[i];
    }

    //multiplication by golden ratio
    return static_cast<u_int32_t>(table_size * (key * PHI - floor(key * PHI))) % table_size;

}


bool cuckooHash::insert(std::vector<std::optional <book>>& table1,std::vector<std::optional<book>>& table2,const book &Book)
{
    //hash books using both functions 
    size_t index1 = hash1(Book.Title,table1.size());
    size_t index2 = hash2(Book.Title,table2.size());
    //base case we have a cycle in the hashing process
    size_t hashed_index_size = this->hashed_indexes.size();
    for(int i = 0; i < hashed_index_size; i++)
    {
        //check if indexes already exist
        if(this->hashed_indexes[i] == index1 || this->hashed_indexes[i] == index2)
        {
            //reset table for the next time the user inserts data
            this->hashed_indexes.clear();
            return false;//insertion failed
        }

    }

    //no cycle detected so push the hashed indexes (index1 and index2) in the vector
    this->hashed_indexes.push_back(index1);
    this->hashed_indexes.push_back(index2);


    /*
        Now we are proceeding into inserting the book on the appropriate index 
        starting from table1 and the index1 of table 1 is not already occupied
    */
   if(!table1[index1].has_value())
   {
        table1[index1] = Book;
   }

   return true;

}