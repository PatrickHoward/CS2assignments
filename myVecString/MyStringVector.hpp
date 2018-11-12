#pragma once

#include <initializer_list>
#include <iterator>

#include "MyString.hpp"


class myStringVector
{
public:
    using iterator = MyString*;
    using const_iterator = const MyString*;

    myStringVector();

    myStringVector(std::initializer_list<MyString> list);

    myStringVector(const myStringVector& vekt);

    //Pr - Nothing, expects the object to be created already (more thrilling than Hitchcock)
    //Po - As the name suggests, returns a boolean value if the size is equal to 0 (empty).
    bool empty() const;

    //Pr - Mary Poppins may be needed (I may be lying there, nothing is needed)
    //Po - Returns a size_t int that is the value of the vector.
    std::size_t size() const;

    //Pr - Memes of American Illuminati are required
    //Po - Returns a size_t value that shows the capacity of the vector. 
    std::size_t capacity() const;

    //Pr - Takes an interger that is n strings in memory.
    //Po - Void function, read the precondition
    void reserve(int cap);

    //Pr - Takes in an interger that resizes the vector based on capacity.
    //Po - Void function, read the precondition.
    void resize(int cap);

    //Pr - Needs a vector to not be empty 
    //Po - Clears the vector complrtely of all strings.
    void clear();

    //Pr - Needs a vector to append to. Appends element
    //Po - Void function, what a goddamn surprise.
    void push_back(MyString element);

    //Pr - Takes in nothing, needs a nonemmpty vector.
    //Po - Void function, pops a value back out.
    void pop_back();

    MyString* data();

    //Pr - Nothing
    //Po - Returns an iterator at the beginning of the vector
    iterator begin() const;

    //Pr - Nothing
    //Po - Returns an iterator at the ending of the vector.
    iterator end() const;

    
    bool operator==(const myStringVector& vekt) const;
    bool operator>(const myStringVector& vekt) const;
    bool operator<(const myStringVector& vekt) const;
    bool operator>=(const myStringVector& vekt) const;
    bool operator<=(const myStringVector& vekt) const;

    void operator= (const myStringVector& vekt);
    MyString& operator[] (int loc) const;
    

    ~myStringVector();

private:
    bool isFull()
    {
        return vecSize > vecCapa;
    }

    std::size_t vecSize;
    std::size_t vecCapa;

    iterator beginning;
    iterator ending; 

    MyString* dynaArray;
};