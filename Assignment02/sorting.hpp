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
      void merge(LinearList<T>& A,int low,int q,int high);
      void quickSort(LinearList<T>& A, int low, int high);
      int partition(LinearList<T>& A,int low,int high);
  };

  template<class T>
  void Sort<T>::insertionSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
      cout<<"You have given wrong parameters"<<endl;
    else{
      for(int i=low+1;i<=high;++i){
        int j=i;
        while(j>0 && A[j-1]>A[i]){
          int temp=A[j];
          A[j]=A[j-1];
          A[j-1]=temp;
        }
      }
    }
    cout<<"-------------------------------------------------"<<endl;
    cout<<"The list has been sorted according to the parameters given."<<endl;
    cout<<"The list in the given parameters is : ";
    for(int i=low;i<=high;++i)
      cout<<A[i]<<" ";
    cout<<endl;
    cout<<"-------------------------------------------------"<<endl;
  }

  template<class T>
  void Sort<T>::rankSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
      cout<<"You have given wrong parameters"<<endl;
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
    cout<<"The list has been sorted according to the parameters given."<<endl;
    cout<<"The list in the given parameters is : ";
    for(int i=low;i<=high;++i)
      cout<<A[i]<<" ";
    cout<<endl;
  }

  template<class T>
  void Sort<T>::bubbleSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
      cout<<"You have given wrong parameters"<<endl;
    else{
      int n=high-low+1;
      bool swapped=true;
      while(swapped!=false){
        swapped=false;
        for(int i=low+1;i<=high;++i){
          if(A[i-1]>A[i]){
            int temp=A[i];
            A[i]=A[i-1];
            A[i-1]=temp;
            swapped=true;
          }
        }
      }
    }
    cout<<"The list has been sorted according to the parameters given."<<endl;
    cout<<"The list in the given parameters is : ";
    for(int i=low;i<=high;++i)
      cout<<A[i]<<" ";
    cout<<endl;
  }

  template<class T>
  void Sort<T>::selectionSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
      cout<<"You have given wrong parameters"<<endl;
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
    cout<<"The list has been sorted according to the parameters given."<<endl;
    cout<<"The list in the given parameters is : ";
    for(int i=low;i<=high;++i)
      cout<<A[i]<<" ";
    cout<<endl;
  }

  template<class T>
  void Sort<T>::mergeSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
      cout<<"You have given wrong parameters"<<endl;
    else{
      int q=(low+high)/2;
      mergeSort(A,low,q);
      mergeSort(A,q+1,high);
      merge(A,low,q,high);
    }
  }

  template<class T>
  void Sort<T>::merge(LinearList<T>& A,int low,int q,int high){
    int n1=q-low+1;
    int n2=high-q;
    LinearList<T> L(n1+1);
    LinearList<T> R(n2+1);
    for(int i=0;i<n1;++i)
      L.push_back(A[low+i]);
    for(int i=0;i<n2;++i)
      R.push_back(A[q+j+1]);
    L[n1]=numeric_limits<T>::max();
    R[n2]=numeric_limits<T>::max();
    int i=0;
    int j=0;
    for(k=low;k<=high;++k){
      if(L[i]<=R[j]){
        A[k]=L[i];
        i++;
      }
      else{
        A[k]=R[j];
        j++;
      }
    }
  }

  template<class T>
  void Sort<T>::quickSort(LinearList<T>& A,int low,int high){
    if(low>high || low>A.length()-1 || high>A.length()-1 || low<0 || high<0)
      cout<<"You have given wrong parameters"<<endl;
    else{
      int q=partition(A,low,high);
      quickSort(A,low,q);
      quickSort(A,q+1,high);
    }
  }

  template<class T>
  int Sort<T>::partition(LinearList<T>& A,int low, int high){
    T pivot=A[high];
    int i=low-1;
    for(j=low;j<high;++j){
      if(A[j]<=pivot){
        i++;
        T temp;
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
      }
    }
    T temp;
    temp=A[high];
    A[high]=A[i+1];
    A[i+1]=temp;
    return i+1;
  }
}

#endif  /* _SORTING_HPP */
