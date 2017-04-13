/******************************************************************************
Author : Abhishek
Roll No. : B15103
CS202 - ADSA - Assignment05 - Hashing header file
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>

namespace cs202_hash{
    unsigned int primary_hash_map(const std::string& key){
        unsigned int returning_number = 0;
        for (int i = key.size() - 1; i >= 0; i--)
        {
            returning_number += (returning_number * 33) + (unsigned int)key[i];
        }
        return returning_number;
    }
}