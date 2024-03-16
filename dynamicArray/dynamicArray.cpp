#include "dynamicArray.h"

//Constructors & destructor
template <typename T>
DynamicArray<T>::DynamicArray()
{
    currentSize = 0;
    maxSize = 1;
    arr = new T[maxSize]; //dynamically allocates an array of size 1.
}
template <typename T>
DynamicArray<T>::DynamicArray(T* arr2, int max, int current)
{
    maxSize = max;
    currentSize = current;
    arr = new T[currentSize];
    for(int i=0; i<currentSize; i++)
    {
        arr[i] = arr2[i];
    }
}
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& rhs)
{
    maxSize = rhs.maxSize;
    currentSize = rhs.currentSize;
    arr = new T[currentSize];
    for(int i = 0; i < currentSize; i++)
    {
        arr[i] = rhs.arr[i];
    }
}
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete [] arr;
}

//getters
template <typename T>
T* DynamicArray<T>::getArr()
{
    return arr;
}
template <typename T>
int DynamicArray<T>::getMaxSize()
{
    return maxSize;
}
template <typename T>
int DynamicArray<T>::getCurrentSize() const
{
    return currentSize;
}

//setters
template <typename T>
void DynamicArray<T>::setArr(T* arr2)
{
    for(int i=0; i<currentSize; i++)
    {
        arr[i] = arr2[i];
    }
}
template <typename T>
void DynamicArray<T>::setMaxSize(int max)
{
    maxSize = max;
}
template <typename T>
void DynamicArray<T>::setCurrentSize(int current)
{
    currentSize = current;
}

//assignment operator overload
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& rhs)
{
    delete [] arr;

    maxSize = rhs.maxSize;
    currentSize = rhs.currentSize;

    arr = new T[maxSize];
    for(int i=0; i<currentSize; i++)
    {
        arr[i] = rhs.arr[i];
    }
    return *this;
}

//adder
template <typename T>
void DynamicArray<T>::addElement(const T& element)
{
    if(currentSize == maxSize)
    {
        resizeArr(); 
    }
    arr[currentSize] = element;
    currentSize++;
}

//return
template <typename T>
T DynamicArray<T>::returnElement(const int position) const
{
    return arr[position];
}

//delete
template <typename T>
void DynamicArray<T>::deleteArray()
{
    delete [] arr;
    maxSize = 1;
    currentSize = 0;
    arr = new T[maxSize];
}