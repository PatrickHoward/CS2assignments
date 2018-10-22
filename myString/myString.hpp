#pragma once

/*
    String Class by Patrick M. Howard - pmh41
    pmh41@zips.uakron.edu
    COPYRIGHT(C) 2018 Patrick M. Howard
*/

#include <cstdint>
#include <limits>

class MyString
{
public:
    static const std::size_t npos = INT32_MAX;

    MyString();//Default constructor.

    MyString(const char* literal); //Constructor intiializing for a string literal.

    MyString(const char* literal, int n); //Constructor initilaizing with a string literal of a specific size n.

    MyString(const MyString& s); //Copy Constructor

    void operator=(const char* literal);//Assigns a string literal to an object.

    void operator=(const MyString& s);//Assigns another MyString object to the "this" object

    void operator+=(const MyString& s);//Concatenates two MyString objects and assigns to the "this" object.

    bool empty() const;//Checks to see if length == 0.

    std::size_t size() const; //Accessor funciton for size.

    char& operator[](std::size_t index) const;

    const char* data() const;//Provdies Cstring access

    std::size_t find(char c) const;//Finds char "c" witin the string.

    MyString substr(int startPos, int length) const;//Slices up a string based on a start position and a number of characters (length)

    bool operator==(const MyString& s) const;//Checks for equality

    bool operator!=(const MyString& s) const;//Checks for inequality

    bool operator<(const MyString& s) const;//Checks for less than lexicographically

    bool operator>(const MyString& s) const;//Checks for greater than lexicographically

    bool operator<=(const MyString& s) const;//Checks for less than/equality lexicongraphically

    bool operator>=(const MyString& s) const;//Checks for greater than/equality lexicongraphically

    MyString operator+(const MyString& s) const;//Concatenates two strings. Takes in a MyString object.

    ~MyString();//Destructor


private:

    //Pre: Takes in a string literal
    void assign(const char* value);
    
    //Pre: Nothing;
    void cleanup();

    std::size_t length;
    char* str;

};