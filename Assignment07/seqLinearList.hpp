/******************************************************************
Author : Abhishek
Roll No : B15103
ADSA Assignment 07 - Sequential Linear List header file
******************************************************************/
#ifndef _SEQ_LINEAR_LIST
#define _SEQ_LINEAR_LIST 1

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <exception>

namespace cs202 {
	template<class T>
	class LinearList{
		private:
        	T* buffer_;
        	unsigned int size_;
        	unsigned int capacity_;
      	public:
        // Default Constructor
        // Creates a zero sized LinearList
        	LinearList();

        // Constructor with size as input
        	LinearList(const int& isize);                   

        // Constuctor with size and default value as input
        	LinearList(const int& isize, const T ival);    

        // Default Destructor
        	~LinearList();                                  

        // Accessing an element of the LinearList using operator
        	inline T& operator[](const int& i){
        		return buffer_[i];
        	};         

        // Return the element in the list at position k
        	inline T at(const int& k){
        		return buffer_[k];
        	};         

        // Appending an element to the LinearList
        // The asymptotic time complexity of this function
        // should be O(1)
        	void push_back(const T item);              

        // Returns true if LinearList is empty
        	bool empty();                               

        // Returns the size of the LinearList
        	inline unsigned int size(){
        		return size_;
        	};                                 

        // Returns the capacity of the LinearList
        	inline unsigned int capacity(){
        		return capacity_;
        	};                                 

        // Fills all the elements with a default value
        	void fill(const T item);                   

        // Resizes the LinearList
        	void resize(const int& n); 

        // Find the index of first occurence of an item in the list
        // Return size of list if item not found
        // 0-based indexing
        	int find(const T item);

        // Remove all occurences of an item in the list
        	void erase(const T item);

        // Remove the item in the list at position pos
        	void erase_pos(const int& pos);

        // Insert item at position k
        	void insert(const T item, const int& k);

			void swapper(const int& pos1, const int& pos2){
				if (pos1 < size_ && pos2 < size_){
					T temp = buffer_[pos1];
					buffer_[pos1] = buffer_[pos2];
					buffer_[pos2] = temp;
				}
			}
  	};

  	template<class T>
  	LinearList<T>::LinearList(void){
  		buffer_ = (T *)NULL;
  		capacity_ = 0;
  		size_ = 0;
	}

	template<class T>
	LinearList<T>::LinearList(const int& isize){
		capacity_ = isize;
		size_ = 0;
		buffer_ = new T[capacity_];
	}

	template<class T>
	LinearList<T>::LinearList(const int& isize, const T ival){
		capacity_ = isize;
		size_ = capacity_;
		buffer_ = new T[capacity_];
		for(int i=0; i < capacity_; ++i)
			buffer_[i] = ival;
	}

	template<class T>
	LinearList<T>::~LinearList(void){
		free(buffer_);
	}

	template<class T>
	void LinearList<T>::push_back(const T item){
		if(size_>=capacity_){
			resize(capacity_ + 1);
		}
		buffer_[size_]=item;
		size_++;
	}

	template<class T>
	bool LinearList<T>::empty(){
		if(size_==0)
			return true;
		else
			return false;
	}

	template<class T>
	void LinearList<T>::fill(const T item){
		for (int i = 0; i < capacity_; ++i)
		{
			buffer_[i]=item;
		}
	}

	template<class T>
	void LinearList<T>::resize(const int& n){
		T* new_buffer = new T[n];
		int mini = 0;
		if(n < size_)
			mini = n;
		else
			mini = size_;
		for(int i = 0; i < mini; ++i){
			new_buffer[i] = buffer_[i];
		}
		delete[] buffer_;
		buffer_ = new_buffer;
	}

	template<class T>
	int LinearList<T>::find(const T item){
		int i;
		for(i=0;i<size_;++i){
			if(buffer_[i]==item){
				break;
			}
		}
		return i;
	}

	template<class T>
	void LinearList<T>::erase(const T item){
		for (int i = 0; i < size_; ++i){
			if(buffer_[i]==item){
				for (int j = i; j < size_ - 1; ++i){
					buffer_[i]=buffer_[i+1];
				}
				size_--;
			}
		}
	}

	template<class T>
	void LinearList<T>::erase_pos(const int& pos){
		if(pos >= size_){
			throw -1;
		}
		else{
			for(int i = pos;i < size_-1; ++i){
				buffer_[i] = buffer_[i+1];
			}
			size_--;
		}
	}

	template<class T>
	void LinearList<T>::insert(const T item, const int& k){
		if(size_ >= capacity_){
			resize(capacity_ + 1);
		}
		if(k >= capacity_){
			resize(k + 1);
		}
		buffer_[k] = item;
		size_++;
	}

}

#endif  /* _SEQ_LINEAR_LIST */