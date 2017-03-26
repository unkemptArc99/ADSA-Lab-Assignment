/*************************************************************************
Author : Abhishek
Roll No : B15103
CS202 - ADSA Lab Assignment 04 - Double Hash Map header file
**************************************************************************/
/*
 * DoubleHashMap.hpp
 *
 * This is an interface for a hash table using Double Hashing.
 */

#ifndef DOUBLEHASHMAP_HPP_
#define DOUBLEHASHMAP_HPP_
#include <cstdlib>
#include <iostream>
#include "../Assignment03/list.hpp"
#include "dictionary.hpp"
#include <cmath>
#include <limits>
#include <exception>

namespace cs202
{

bool isPrime(int n){
    if(n%2==0 || n%3==0)
        return false;
    for(int i = 5; i <= (int)sqrt(n); i+=6){
        if(n%i == 0){
            return false;
        }
    }
    for(int i = 7; i<= (int)sqrt(n); i+=6){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int nextPrime(int n){
    int i = n+1;
    while(1){
        if(isPrime(i))
            return i;
        else
            i++;
    }
}

class storageException{
    virtual const char* what() const throw()
    {
        return "Hash-table full";
    }
} stEx;

class unavailableException{
    virtual const char* what() const throw()
    {
        return "Cannot find in the hash-table";
    }
} unEx;

template<class Key, class Value>
class DoubleHashMap  : public Dictionary<Key,Value>
{
private:
    Value *vals;
    Key *keys;
    int maxlength;
    int length;
public:
    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
    void rehash();
    /*
     * Constructor: DoubleHashMap
     * Creates a Double Hash Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	DoubleHashMap();
    /*
     * Constructor:DoubleHashMap
     * Creates an empty Double Hash Map with the ability to hold atleast num Key value pairs.
     */
	DoubleHashMap(const int& num);
    /*
     * Constructor: Double Hash Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	DoubleHashMap(DoubleHashMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~DoubleHashMap();
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * DoubleHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key);
};


}

#endif 