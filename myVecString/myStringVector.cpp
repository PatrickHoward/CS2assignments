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
    for(MyString const& element:list)
    {
        push_back(element);
    }

    beginning = &dynaArray[0];
    ending = &dynaArray[vecSize];

}

myStringVector::myStringVector(const myStringVector& vekt)
    : vecSize(vekt.vecSize),
    vecCapa(vekt.vecCapa)
{
    

}

bool myStringVector::empty() const
{
    return (vecSize == 0) ? true : false;
}

std::size_t myStringVector::size() const
{
    return vecSize;
}

std::size_t myStringVector::capacity() const
{
    return vecCapa;        
}

void myStringVector::reserve(int cap)
{
    vecCapa += cap;

    MyString* tmpArray = new MyString[vecCapa];

    for (int i = 0; i < vecSize; ++i)
    {
        tmpArray[i] = dynaArray[i];
    }

    delete[] dynaArray;

    dynaArray = tmpArray;

    delete[] tmpArray;
}

void myStringVector::resize(int cap)
{
    vecCapa = 1;
    reserve(cap);
}

void myStringVector::clear()
{
    vecCapa = 1;
    vecSize = 0;

    MyString* tmpArray = new MyString[vecCapa];
    tmpArray[vecSize] = "";

    delete[] dynaArray;
    dynaArray = tmpArray;
    delete[] tmpArray;
}

myStringVector::iterator myStringVector::begin() const
{
    return beginning;
}

myStringVector::iterator myStringVector::end() const
{
    return ending;
}

void myStringVector::push_back(MyString element)
{
    if(isFull())
    {
        reserve(vecCapa);
        ++vecCapa; 
    }

    --vecSize;
    dynaArray[vecSize] = element;
    ending = &dynaArray[vecSize];
}

void myStringVector::pop_back()
{
    dynaArray[vecSize] = "";
    --vecSize;

    ending = &dynaArray[vecSize];
}

bool myStringVector::operator== (const myStringVector& vekt) const
{
    
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

}

MyString& myStringVector::operator[] (int loc) const
{

}

myStringVector::~myStringVector()
{
    delete[] dynaArray;
}
