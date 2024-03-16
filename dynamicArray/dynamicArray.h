//General personally designed implementation of a dynamic array for the currentOrder<MenuItem> array for each customer.

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class DynamicArray
{
    T* arr = new T[100]; //Arbitrary large number
    int maxSize;
    int currentSize;

    void resizeArr()
    {
        T* tempArr = new T[currentSize];
        for(int i=0; i<currentSize; i++)
        {
            tempArr[i] = arr[i];
        }
        delete [] arr;

        maxSize *= 2;
        arr = new T[maxSize];
        for(int i=0; i<currentSize; i++)
        {
            arr[i] = tempArr[i];
        }
        delete [] tempArr;
    }

    public:
        DynamicArray();
        DynamicArray(T*, int, int);
        DynamicArray(const DynamicArray& rhs);
        ~DynamicArray();

        T* getArr();
        int getMaxSize();
        int getCurrentSize() const;

        void setArr(T*);
        void setMaxSize(int);
        void setCurrentSize(int);

        DynamicArray<T>& operator=(const DynamicArray<T>&);
        void addElement(const T&);
        T returnElement(const int) const;
        void deleteArray();
};
#endif