#ifndef _SEQ_LINEAR_LIST
#define _SEQ_LINEAR_LIST 1

#include <iostream>
#include <string.h>

namespace cs202 {
	template<typename T>
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
        	LinearList(const int& isize, const T& ival);    

        // Default Destructor
        	~LinearList();                                  

        // Accessing an element of the LinearList using operator
        	inline T& operator[](const int& i){
        		return buffer_[i];
        	};         

        // Return the element in the list at position k
        	inline T& at(const int& k){
        		return buffer_[k];
        	};         

        // Appending an element to the LinearList
        // The asymptotic time complexity of this function
        // should be O(1)
        	void push_back(const T& item);              

        // Returns true if LinearList is empty
        	bool empty();                               

        // Returns the size of the LinearList
        	unsigned int size(){
        		return size_;
        	};                                 

        // Returns the capacity of the LinearList
        	unsigned int capacity(){
        		return capacity_;
        	};                                 

        // Fills all the elements with a default value
        	void fill(const T& item);                   

        // Resizes the LinearList
        	void resize(const int& n); 

        // Find the index of first occurence of an item in the list
        // Return size of list if item not found
        // 0-based indexing
        	int find(const T& item);

        // Remove all occurences of an item in the list
        	void erase(const T& item);

        // Remove the item in the list at position pos
        	void erase_pos(const int& pos);

        // Insert item at position k
        	void insert(const T& item, const int& k);

        // Iterator class for LinearList
        // This should be used to traverse the LinearList
        // See std::vector<T>::iterator for more understanding
        // on how iterators work
        	class iterator{                             
          		private:
            		T* elem_;
          		public:
            		iterator();
            		iterator(T* ptr);
            		~iterator();
            		T& operator*();
            		void operator=(T *ptr);
            		void operator=(iterator iter);
            		void operator++();
            		void operator--();
            		bool operator!=(T* ptr);
            		bool operator==(T* ptr);
            		bool operator!=(iterator iter);
            		bool operator==(iterator iter);
            		iterator operator+(int i);
            		iterator operator-(int i);
        	};
        	iterator begin();                       
        	iterator end();
  	};

  	template<typename T>
  	LinearList<T>::LinearList(void){
  		cout<<"-----------------------------------------------"<<endl;
		cout<<"The list is being created"<<endl;
		cout<<"-----------------------------------------------"<<endl;
	}

	template<typename T>
	LinearList<T>::LinearList(const int& isize){
		capacity_=isize;
		size_=0;
		buffer_=(T *)malloc(capacity_*sizeof(T));
		for(int i=0;i<capacity_;++i)
			buffer_[i]=(T)NULL;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"The list is being created"<<endl;
		cout<<"The maximum size of the list is "<<capacity_<<endl;
		cout<<"-----------------------------------------------"<<endl;
	}

	template<typename T>
	LinearList<T>::LinearList(const int& isize, const T& ival){
		capacity_=isize;
		size_=capacity_;
		buffer_=(T *)malloc(capacity_*sizeof(T));
		for(int i=0;i<capacity_;++i)
			buffer_[i]=ival;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"The list is being created"<<endl;
		cout<<"The maximum size of the list is "<<capacity_<<endl;
		cout<<"The default variable in the list is "<<ival<<endl;
		cout<<"-----------------------------------------------"<<endl;
	}

	template<typename T>
	LinearList<T>::~LinearList(void){
		free(element);
		cout<<"-----------------------------------------------"<<endl;
		cout<<"The list has been deleted"<<endl;
		cout<<"-----------------------------------------------"<<endl;
	}

	template<typename T>
	void LinearList<T>::push_back(const T& item)
	{
		if(size_>=capacity_){
			cout<<"-----------------------------------------------"<<endl;	
			cout<<"The list is full!! Cannot add new number"<<endl;
			cout<<"-----------------------------------------------"<<endl;
		}
		else{
			buffer_[size_]=iteml
			size_++;
		}
	}

	template<typename T>
	bool LinearList<T>::empty(){
		if(size_==0)
			return true;
		else
			return false;
	}

	template<typename T>
	void LinearList<T>::fill(const T& item){
		for (int i = 0; i < capacity_; ++i)
		{
			buffer_[i]=item;
		}
	}

	template<typename T>
	void LinearList<T>::resize(const int& n){
		buffer_=(T *)realloc(buffer_,n*sizeof(T));
		capacity_=n;
		if(n<size_)
			size_=n;
	}

	template<typename T>
	int LinearList<T>::find(const T& item){
		int i;
		for(i=0;i<size_;++i){
			if(buffer_[i]==item){
				break;
			}
		}
		return i;
	}

	template<typename T>
	void LinearList<T>::erase(const T& item){
		for (int i = 0; i < size_; ++i){
			if(buffer_[i]==item){
				for (int j = i; j < size_-1; ++i){
					buffer_[i]=buffer_[i+1];
				}
				buffer_[size_-1]=(T*)NULL;
				size_--;
			}
		}
	}

	template<typename T>
	void LinearList<T>::insert(const T& item, const int& k){
		if(size_>=capacity_){
			cout<<"-----------------------------------------------"<<endl;
			cout<<"There is no space for extra input"<<endl;
			cout<<"-----------------------------------------------"<<endl;
		}
		else if(size_==0){
			size_++;
			buffer_[k]=item;
		}
		else{
			size_++;
			for(int i=size_-1;i>k;i--){
				buffer_[i]=buffer_[i-1];
			}
			buffer_[k]=x;
		}
	}

}

#endif  /* _SEQ_LINEAR_LIST */

