#include "cuckoo.hpp"


uint32_t cuckooHash::hash1(const std::string& bookName,size_t table_size)
{
    uint32_t key = 0;
    size_t stringSize = bookName.size();
    //iterate over the string and calculate its alphanumeric value
    for(int i = 0; i < stringSize; i++)
    {
        key += bookName[i];
    }

    return static_cast<u_int32_t>(key % A) % table_size;
}


uint32_t cuckooHash::hash2(const std::string& bookName,size_t table_size)
{
    uint32_t key = 0;
    size_t stringSize = bookName.size();
    //iterate over the string and calculate its alphanumeric value
    for(int i = 0; i < stringSize; i++)
    {
        key += bookName[i];
    }

    //multiplication by golden ratio
    return static_cast<u_int32_t>(table_size * (key * PHI - floor(key * PHI))) % table_size;

}