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
#include <string>

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
public:
    Value *vals;
    Key *keys;
    int maxlength;
    int length;
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

    unsigned int primary_hash_map(const Key& key){
        unsigned int returning_number = 0;
        for (int i = 0; i < key.length(); ++i)
        {
            returning_number += (unsigned int)(key[i]) * (unsigned int)(pow(33,i));
        }
        return returning_number;
    };

    int hash_function(const Key& key, const int& maxlength){
        unsigned int x = primary_hash_map(key);
        return x % maxlength;
    };

    inline int capacity(void){
        return maxlength;
    };

    inline int size(void){
        return length;
    };

    inline void print(void){
        for(int i = 0; i < maxlength; ++i){
            if(keys[i] > std::numeric_limits<Key>::min()){
                std::cout<<"Key : "<<keys[i]<<" Value : "<<vals[i]<<std::endl;
            }
        }
    }

    bool has(const Key& key){
        int i = 0;
        int j = hash_function(key,maxlength);
        while(keys[j] != key && i < maxlength){
            j = (j + 1)%maxlength;
            i++;
        }
        if(i == maxlength)
            return false;
        else
            return true;
    };

    void remove(const Key& key){
        int i = 0;
        int j = hash_function(key,maxlength);
        while(keys[j] != key && i < maxlength){
            j = (j + 1) % maxlength;
            i++;
        }
        if(i == maxlength)
            return;
        else{
            vals[j] = std::numeric_limits<Value>::min();
            keys[j] = std::numeric_limits<Key>::min();
            length--;
        }   
    };

    Value get(const Key& key){
        int i = 0;
        int j = hash_function(key,maxlength);
        while(keys[j] != key && i < maxlength){
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
        int j = hash_function(key,maxlength);
        while(keys[j] != key && i < maxlength){
            j = (j + 1)%maxlength;
            i++;
        }
        if(i == maxlength){
            int p = 0;
            int q = hash_function(key,maxlength);
            while(vals[q] != std::numeric_limits<Value>::min() && p < maxlength){
                q = (q + 1) % maxlength;
                p++;       
            }
            if(p == maxlength){
                throw -2;
                rehash();
            }
            else{
                vals[q] = value;
                keys[q] = key;
                length++;
            }
        }
        else{
            vals[j] = value;
            length++;
        }
    };

    Key max_val(void){
        Key max_key = std::numeric_limits<Key>::min();
        Value max_value = std::numeric_limits<Value>::min();
        for(int i = 0; i < maxlength; ++i){
            if(max_value < vals[i]){
                max_value = vals[i];
                max_key = keys[i];
            }
        }
        return max_key;
    };
};

template<class Key,class Value>
OpenMap<Key,Value>::OpenMap(void){
    maxlength = 97;
    vals = new Value[maxlength];
    keys = new Key[maxlength];
    length = 0;
    for(int i = 0; i < maxlength; ++i){
        vals[i] = std::numeric_limits<Value>::min();
        keys[i] = std::numeric_limits<Key>::min();
    }
}

template<class Key,class Value>
OpenMap<Key,Value>::OpenMap(const int& num){
    if(isPrime(num))
        maxlength = num;
    else
        maxlength = nextPrime(num);
    vals = new Value[maxlength];
    keys = new Key[maxlength];
    for(int i = 0; i < maxlength; ++i){
        vals[i] = std::numeric_limits<Value>::min();
        keys[i] = std::numeric_limits<Key>::min();
    }
    length = 0;
}

template<class Key,class Value>
OpenMap<Key,Value>::OpenMap(OpenMap<Key,Value>& ht){
    maxlength = ht.capacity();
    length = 0;
    vals = new Value[maxlength];
    keys = new Key[maxlength];
    for (int i = 0; i < maxlength; ++i)
    {
        vals[i] = ht.vals[i];
        keys[i] = ht.keys[i];
    }
}

template<class Key,class Value>
Value& OpenMap<Key,Value>::operator[](const Key& key){
    int i = 0;
    int j = hash_function(key,maxlength);
    while(keys[j] != key && i < maxlength){
        j = (j + 1)%maxlength;
        i++;
    }
    if(i == maxlength){
        put(key,std::numeric_limits<Value>::min());
    }
    else
        return vals[j];
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