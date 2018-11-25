#include <algorithm>

#include "myStringVector.hpp"
#include "MyString.hpp"

myStringVector::myStringVector()
{
    vecSize = 0;
    vecCapa = 1;

    dynaArray = new MyString[vecCapa];
    dynaArray[vecSize] = "";

    beginning = &dynaArray[vecSize];
    ending = &dynaArray[vecSize];
}

myStringVector::myStringVector(std::initializer_list<MyString> list)
    : vecSize(list.size()),
    vecCapa(list.size()+1)
{
    for(const MyString& element : list)
    {
        push_back(element);
    }
}

myStringVector::myStringVector(const myStringVector& vekt)
    : vecSize(vekt.vecSize),
    vecCapa(vekt.vecCapa)
{
    dynaArray = new MyString[vecCapa];
    for (int i = 0; i < vekt.vecSize; ++i)
    {
        dynaArray[i] = vekt.dynaArray[i];
    }
}

bool myStringVector::empty() const
{
    return vecSize == 0;
}

std::size_t myStringVector::size() const
{
    return vecSize;
}

std::size_t myStringVector::capacity() const
{
    return vecCapa;        
}

void myStringVector::reserve(int newCapacity)
{
    if(newCapacity <= vecCapa)
    {
        return;
    }

    MyString* tmpArray = new MyString[newCapacity];

    for (int i = 0; i < vecSize; ++i)
    {
        tmpArray[i] = dynaArray[i];
    }

    delete[] dynaArray;

    dynaArray = tmpArray;

    vecCapa = newCapacity;
}

void myStringVector::resize(int newSize)
{
    reserve(newSize);
    vecSize = newSize;
}

void myStringVector::clear()
{
    vecSize = 0;
}

myStringVector::iterator myStringVector::begin() const
{
    return &dynaArray[0];
}

myStringVector::iterator myStringVector::end() const
{
    return &dynaArray[vecSize];
}

void myStringVector::push_back(MyString element)
{
    if(isFull())
    {
        ++vecCapa;
        reserve(vecCapa);
    }

    dynaArray[vecSize++] = element;
}

void myStringVector::pop_back()
{
    --vecSize;
}

bool myStringVector::operator==(const myStringVector& vekt) const
{
    if(vecSize != vekt.vecSize)
    {
        return false;
    }

    for(int i = 0; i < vekt.vecSize; ++i)
    {
        if(dynaArray[i] != vekt.dynaArray[i])
        {
            return false;
        }
    }

    return true;
}

bool myStringVector::operator>(const myStringVector& vekt) const
{
    
}

bool myStringVector::operator<(const myStringVector& vekt) const
{

}

bool myStringVector::operator>=(const myStringVector& vekt) const
{

}

bool myStringVector::operator<=(const myStringVector& vekt) const
{

}

void myStringVector::operator= (const myStringVector& vekt)
{
    for(int i = 0; i < vekt.vecSize; ++i)
    {
        dynaArray[i] = vekt.dynaArray[i];
    }
}

MyString& myStringVector::operator[] (int loc) const
{

}

myStringVector::~myStringVector()
{
    delete [] dynaArray;
}
