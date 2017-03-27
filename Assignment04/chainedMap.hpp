/*************************************************************************
Author : Abhishek
Roll No : B15103
CS202 - ADSA Lab Assignment 04 - Chained Map header file
**************************************************************************/
/*
 * ChainedMap.hpp
 *
 */

#ifndef CHAINEDMAP_HPP_
#define CHAINEDMAP_HPP_

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

template<class Key, class Value>
class ChainedMap  : public Dictionary<Key,Value>
{
private:
    list<Value> **mains; 
    int maxlength;
    int *length; 
public:
    /*
     * Function rehash:
     * Resizes the hash table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
    void rehash();
    /*
     * Constructor: ChainedMap
     * Creates a Chained Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	ChainedMap();
    /*
     * Constructor:ChainedMap
     * Creates an empty Chained Map with the ability to hold atleast num Key value pairs.
     */
	ChainedMap(const int& num);
    /*
     * Constructor: Chained Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	ChainedMap(ChainedMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~ChainedMap();
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * ChainedHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key);

    inline int capacity(void){
        return maxlength;
    };

    inline int size(void){
        int sum = 0;
        for (int i = 0; i < maxlength; ++i)
        {
            sum += length[i];
        }
        return sum;
    };

    inline void print(void){
        for(int i = 0; i < maxlength; ++i){
            if(length[i] != 0){
                std::cout<<"Key : "<<i<<std::endl;
                mains[i]->display();
            }
        }
    }

    bool has(const Key& key){
        if(length[key] != 0)
            return true;
        else
            return false;
    };

    Value search(const Key& key, const Value& x){
        bool flag = false;
        node<Value> *temp;
        temp = mains[key]->head;
        for (int i = 0; i < length[key] && !flag; ++i)
        {
            if(temp->node_val)
                flag = true;
            else
                temp = temp->next;
        }
        if(flag)
            return key;
        else
            throw -1;
    };

    void remove(const Key& key){
        delete mains[key];
        mains[key] = new list<Value>;
        length[key] = 0;
    };

    Value get(const Key& key){
        if(length[key] > 0){
            mains[key]->display();
            return 1;
        }
        else
            throw -1;
    };

    void put(const Key& key,const Value& value){
        mains[key]->cons(value);
        length[key]++;
    };
};

template<class Key, class Value>
ChainedMap<Key,Value>::ChainedMap(void){
    mains = new list<Value>*[97];
    maxlength = 97;
    length = new int[97];
    for (int i = 0; i < 97; ++i)
    {
        length[i] = 0;
        mains[i] = new list<Value>;
    }
}

template<class Key, class Value>
ChainedMap<Key,Value>::ChainedMap(const int& num){
    if(!isPrime(num)){
        num = nextPrime(num);
    }
    mains = new list<Value>*[num];
    maxlength = num;
    length = new int[num];
    for (int i = 0; i < num; ++i)
    {
        length[i] = 0;
        mains[i] = new list<Value>;
    }
}

template<class Key, class Value>
Value& ChainedMap<Key,Value>::operator[](const Key& key){
    if(length[key] > 0){
        return mains[key]->head->node_val;
    }
    else{
        put(key,std::numeric_limits<Value>::min());
    }
}


}
#endif /* CHAINEDMAP_HPP_ */