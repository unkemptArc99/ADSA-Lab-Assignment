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
public:
    list<Value> **mains; 
    list<Key> **mains_key;
    int maxlength;
    int *length; 
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
	~ChainedMap(){
        delete mains;
        delete mains_key;
    };
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

    int hash_function(const Key& key, const int& maxlength){
        return key%maxlength;
    }

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
                std::cout<<"Key : ";
                mains_key[i]->display();
                std::cout<<"Value : ";
                mains[i]->display();
            }
        }
    }

    bool has(const Key& key){
        if(length[hash_function(key,maxlength)] != 0){
            node<Key> *temp = mains_key[hash_function(key,maxlength)]->head;
            while(temp != NULL){
                if(temp->node_val == key){
                    return true;
                }
                else{
                    temp = temp->next;
                }
            }
            if(temp == NULL)
                return false;
        }
        else
            return false;
    };

    void remove(const Key& key){
        if(length[hash_function(key,maxlength)] > 0){
            node<Value> *temp_val = mains[hash_function(key,maxlength)]->head;
            node<Key> *temp_key = mains_key[hash_function(key,maxlength)]->head;
            for (int i = 0; i < length[hash_function(key,maxlength)]; ++i)
            {
                if(temp_key->node_val == key){
                    if(temp_key == mains_key[hash_function(key,maxlength)]->head){
                        mains_key[hash_function(key,maxlength)]->head = mains_key[hash_function(key,maxlength)]->head->next;
                        mains[hash_function(key,maxlength)]->head = mains[hash_function(key,maxlength)]->head->next;
                    }
                    else{
                        node<Value> *temp_val1 = mains[hash_function(key,maxlength)]->head;
                        node<Key> *temp_key1 = mains_key[hash_function(key,maxlength)]->head;
                        for (int j = 1; j < i; ++j)
                        {
                            temp_val1 = temp_val1->next;
                            temp_key1 = temp_key1->next;
                        }
                        temp_key1->next = temp_key->next;
                        temp_val1->next = temp_val->next;
                    }
                    delete temp_key;
                    delete temp_val;
                    length[hash_function(key,maxlength)]--;
                    return;
                }
                else{
                    temp_val = temp_val->next;
                    temp_key = temp_key->next;
                }
            }
        }
    };

    Value get(const Key& key){
        if(length[hash_function(key,maxlength)] > 0){
            node<Value> *temp_val = mains[hash_function(key,maxlength)]->head;
            node<Key> *temp_key = mains_key[hash_function(key,maxlength)]->head;
            for(int i = 0; i < length[hash_function(key,maxlength)]; ++i){
                if(temp_key->node_val == key){
                    return temp_val->node_val;
                }
                else{
                    temp_val = temp_val->next;
                    temp_key = temp_key->next;
                }
            }
        }
        throw -1;
    };

    void put(const Key& key,const Value& value){
        node<Key> *temp = mains_key[hash_function(key,maxlength)]->head;
        node<Value> *temp1 = mains[hash_function(key,maxlength)]->head;
        while(temp != NULL){
            if(temp->node_val == key){
                temp1->node_val = value;
            }
            else{
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
        if(temp == NULL){
            mains[hash_function(key,maxlength)]->cons(value);
            mains_key[hash_function(key,maxlength)]->cons(key);
            length[hash_function(key,maxlength)]++;
        }
        else
            throw -2;
    };
};

template<class Key, class Value>
ChainedMap<Key,Value>::ChainedMap(void){
    mains = new list<Value>*[97];
    mains_key = new list<Key>*[97];
    maxlength = 97;
    length = new int[97];
    for (int i = 0; i < 97; ++i)
    {
        length[i] = 0;
        mains[i] = new list<Value>;
        mains_key = new list<Key>;
    }
}

template<class Key, class Value>
ChainedMap<Key,Value>::ChainedMap(const int& num){
    int x = num;
    if(!isPrime(x)){
        x = nextPrime(x);
    }
    mains = new list<Value>*[x];
    mains_key = new list<Key>*[x];
    maxlength = x;
    length = new int[x];
    for (int i = 0; i < x; ++i)
    {
        length[i] = 0;
        mains[i] = new list<Value>;
        mains_key[i] = new list<Key>;
    }
}

template<class Key, class Value>
Value& ChainedMap<Key,Value>::operator[](const Key& key){
    if(length[hash_function(key,maxlength)] > 0){
        node<Value> *temp_val = mains->head;
        node<Key> *temp_key = mains_key->head;
        for(int i = 0; i < length[hash_function(key,maxlength)]; ++i){
            if(temp_key->node_val == key){
                return temp_val->node_val;
            }
            else{
                temp_val = temp_val->next;
                temp_key = temp_key->next;
            }
        }
    }
    put(key, std::numeric_limits<Value>::min());
}


}
#endif /* CHAINEDMAP_HPP_ */