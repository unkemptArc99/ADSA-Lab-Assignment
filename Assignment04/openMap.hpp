/*************************************************************************
Author : Abhishek
Roll No : B15103
CS202 - ADSA Lab Assignment 04 - Linear Probe header file
**************************************************************************/
/*
 * OpenMap.hpp
 *
 *This is a Hash Table interface using Linear Probing
 */

#ifndef OPENMAP_HPP_
#define OPENMAP_HPP_
#include <cstdlib>
#include <iostream>
#include "../Assignment03/list.hpp"
#include "dictionary.hpp"
#include <cmath>
#include <limits>
#include <exception>

namespace cs202{
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

//-1 is for unavailability exception and -2 is for storage exception.

template<class Key, class Value>
class OpenMap  : public Dictionary<Key,Value>
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
     * Constructor: OpenMap
     * Creates a Open Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
    OpenMap();
    /*
     * Constructor:OpenMap
     * Creates an empty Open Map with the ability to hold atleast num Key value pairs.
     */
    OpenMap(const int& num);
    /*
     * Constructor: Open Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
    OpenMap(OpenMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
    ~OpenMap(){
        delete vals;
        delete keys;
    };
     /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * OpenMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
    Value& operator[](const Key& key);

    inline int capacity(void){
        return maxlength;
    };

    inline int size(void){
        return length;
    };

    inline void print(void){
        for(int i = 0; i < maxlength; ++i){
            if(vals[i] == std::numeric_limits<Value>::min())
                std::cout<<"N/A"<<std::endl;
            else
                std::cout<<vals[i]<<std::endl;
        }
    }

    bool has(const Key& key){
        int i = 0;
        int j = key;
        while(vals[j] == std::numeric_limits<Value>::min() && i < maxlength){
            j = (j + 1)%maxlength;
            i++;
        }
        if(i == maxlength)
            return false;
        else
            return true;
    };

    Value search(const Key& key, const Value& x){
        int i = 0;
        int j = key;
        while(vals[j]!=std::numeric_limits<Value>::min() && i < maxlength){
            if(vals[j] == x)
                return j;
            else{
                j = (j + 1) % maxlength;
                i++;
            }   
        }
        if(i == maxlength || vals[j] == std::numeric_limits<Value>::min())
            throw -1;
    };

    void remove(const Key& key){
        int i = 0;
        int j = key;
        while(vals[j] == std::numeric_limits<Value>::min() && i < maxlength){
            j = (j + 1) % maxlength;
            i++;
        }
        if(i == maxlength)
            return;
        else{
            vals[j] == std::numeric_limits<Value>::min();
            keys[j] == std::numeric_limits<Value>::min();
            length--;
        }   
    };

    Value get(const Key& key){
        int i = 0;
        int j = key;
        while(vals[j] == std::numeric_limits<Value>::min() && i < maxlength){
            j = (j + 1)%maxlength;
            i++;
        }
        if(i == maxlength)
            throw -1;
        else
            return vals[j];
    };

    void put(const Key& key,const Value& value){
        int i = 0;
        int j = key;
        while(vals[j] != std::numeric_limits<Value>::min() && i < maxlength){
            j = (j + 1) % maxlength;
            i++;   
        }
        if(i == maxlength){
            throw -2;
            //rehash();
        }
        else{
            vals[j] = value;
            keys[j] = key;
        }
    };
};

template<class Key,class Value>
OpenMap<Key,Value>::OpenMap(void){
    maxlength=97;
    vals = new Value[maxlength];
    keys = new Value[maxlength];
    length = 0;
    for(int i = 0; i < maxlength; ++i){
        vals[i] = std::numeric_limits<Value>::min();
        keys[i] = std::numeric_limits<Value>::min();
    }
}

template<class Key,class Value>
OpenMap<Key,Value>::OpenMap(const int& num){
    if(isPrime(num))
        maxlength = num;
    else
        maxlength = nextPrime(num);
    vals = new Value[maxlength];
    keys = new Value[maxlength];
    for(int i = 0; i < maxlength; ++i){
        vals[i] = std::numeric_limits<Value>::min();
        keys[i] = std::numeric_limits<Value>::min();
    }
    length = 0;
}

template<class Key,class Value>
OpenMap<Key,Value>::OpenMap(OpenMap<Key,Value>& ht){
    maxlength = ht.capacity();
    length = 0;
    vals = new Value[maxlength];
    keys = new Value[maxlength];
    for(int i = 0; i < maxlength; ++i){
        vals[i] = ht[i];
    }
}

template<class Key,class Value>
Value& OpenMap<Key,Value>::operator[](const Key& key){
    if(vals[key]!=std::numeric_limits<Value>::min())
        return vals[key];
    else{
        put(key,std::numeric_limits<Value>::min());
        return vals[key];
    }
}

template<class Key,class Value>
void OpenMap<Key,Value>::rehash(void){
    for(int i = 0; i < maxlength; ++i){
        if(vals[i] != std::numeric_limits<Value>::min()){
            Key key = keys[i];
            Value value = vals[i];
            put(key,value);
        }
    }
}

}

#endif 