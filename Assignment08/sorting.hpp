#ifndef _SORTING_HPP
#define _SORTING_HPP 1

#include <iostream>
#include <limits>
#include "seqLinearList.hpp"

namespace cs202 {
  template<class T>
  class Sort{
    public:
      void insertionSort(LinearList<T>& A, int low, int high);
      void bubbleSort(LinearList<T>& A, int low, int high);
      void rankSort(LinearList<T>& A, int low, int high);
      void selectionSort(LinearList<T>& A, int low, int high);
      void mergeSort(LinearList<T>& A, int low, int high);
      void merge(LinearList<T>& A,LinearList<T>& left,LinearList<T>& right,int l1,int r1);
      void quickSort(LinearList<T>& A, int low, int high);
      int partition(LinearList<T>& A,int low,int high);
  };

  template<class T>
  void Sort<T>::insertionSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.size()-1 || high>A.size()-1 || low<0 || high<0)
      std::cout<<"You have given wrong parameters"<<std::endl;
    else{
        T key;
        key=A[0];
        for(int j=1;j<=high;++j){
          key=A[j];
          int i=j-1;
          while(i>=0 && A[i]>key){
            A[i+1]=A[i];
            i=i-1;
          }
          A[i+1]=key;
        }
      }
  }

  template<class T>
  void Sort<T>::rankSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.size()-1 || high>A.size()-1 || low<0 || high<0)
      std::cout<<"You have given wrong parameters"<<std::endl;
    else{
      int n=high-low+1;
      int rank[n];
      for(int i=0;i<n;++i)
        rank[i]=0;
      for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
          if(A[j+low]>A[i+low])
            rank[j]++;
          else
            rank[i]++;
        }
      }
      int b[n];
      for(int i=0;i<n;++i)
        b[rank[i]]=A[i+low];
      for(int i=0;i<n;++i)
        A[i+low]=b[i];
    }
   }

  template<class T>
  void Sort<T>::bubbleSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.size()-1 || high>A.size()-1 || low<0 || high<0)
      std::cout<<"You have given wrong parameters"<<std::endl;
    else{
      T swap;
      for(int i=0;i<high;++i){
        for(int j=0;j<high-i;++j){
          if(A[j]>A[j+1]){
            swap=A[j];
            A[j]=A[j+1];
            A[j+1]=swap;
          }
        }
      }
    }
  }

  template<class T>
  void Sort<T>::selectionSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.size()-1 || high>A.size()-1 || low<0 || high<0)
      std::cout<<"You have given wrong parameters"<<std::endl;
    else{
      int n=high-low+1;
      for(int j=low;j<n-1+low;++j){
        int iMin=j;
        for(int i=j+1;i<n+low;++i){
          if(A[i]<A[iMin])
            iMin=i;
        }
        if(iMin!=j){
          int temp=A[j];
          A[j]=A[iMin];
          A[iMin]=temp;
        }
      }
    }
  }

  template<class T>
  void Sort<T>::merge(LinearList<T>& A,LinearList<T>& left,LinearList<T>& right,int l1,int r1){
    int i=0,j=0,k=0;
    while(i<l1 && j<r1){
      if(left[i]>=right[i]){
        A[k]=right[j];
        j++;
        k++;
      }
      else{
        A[k]=left[i];
        i++;
        k++;
      }
    }
    while(i<l1){
      A[k]=left[i];
      k++;
      i++;
    }
    while(j<r1){
      A[k]=right[i];
      k++;
      j++;
    }
  }

  template<class T>
  void Sort<T>::mergeSort(LinearList<T>& A,int low,int high){
    int n=high-low+1;
    int mid=n/2;
    if(mid==0)
      return;

    LinearList<T> left(mid);
    LinearList<T> right(n-mid);
    for(int i=0;i<mid;++i)
      left[i]=A[i];
    for(int i=mid;i<n;++i)
      right[i-mid]=A[i];

    mergeSort(left,0,mid-1);
    mergeSort(right,mid,n-1);
    merge(A,left,right,mid,n-mid);
  }

  template<class T>
  void Sort<T>::quickSort(LinearList<T>& A,int low,int high){
    if(low<high){
       int q = partition( A, low, high);
       quickSort( A, low, q-1);
       quickSort( A, q+1, high);
    }
  }

  template<class T>
  int Sort<T>::partition(LinearList<T>& A,int low, int high){
    int i, j;
    T pivot,t;
    pivot = A[low];
    i = low; j = high+1;

    while(1)
    {
        do ++i;while(A[i]<=pivot&&i<=high);
        do --j;while(A[j]>pivot);
        if(i>=j) break;
        t=A[i];A[i]=A[j];A[j]=t;
    }
    t=A[low];A[low]=A[j];A[j]=t;
    return j;
  }
}

#endif  /* _SORTING_HPP */
