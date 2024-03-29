/*
    String Class by Patrick M. Howard - pmh41
    pmh41@zips.uakron.edu
    COPYRIGHT(C) 2018 Patrick M. Howard
*/

#include "MyString.hpp"
#include <cstring>
#include <cassert>
#include <iostream>

MyString::MyString()
{
    str = new char[1];
    str[0] = '\0';
    length = 0;
}

MyString::MyString(const char* literal)
{
    length = strlen(literal);
    str = new char[length +1];
    
    assign(literal);
}

MyString::MyString(const char* literal, int n)
{
    assert(literal != nullptr);
    assert(strlen(literal) >= n);

    length = n;
    str = new char[length + 1];

    strncpy(str, literal, n);

    str[length] = '\0';
}

MyString::MyString(const MyString& s)
{
    cleanup();
    assign(s.str);
}

void MyString::operator=(const char* literal)
{
    assign(literal);
}

void MyString::operator=(const MyString& s)
{
    cleanup();
    assign(s.str);
}

void MyString::operator+=(const MyString& s)
{
    int newLength = length + s.length;
    char* newStr = new char[newLength + 1];

    strcpy(newStr, str);
    strcat(newStr, s.str);

    cleanup();

    str = newStr;
    length = newLength;
}

bool MyString::empty() const
{
    return length == 0;
}

std::size_t MyString::size() const
{
    return length;
}

char& MyString::operator[](std::size_t index) const
{
    assert(index < length);
    assert(index >= 0);

    return str[index];
}

const char* MyString::data() const
{
    return str;
}

std::size_t MyString::find(char c) const
{
    char* ptr = strchr(str, c);

    return ptr == nullptr
        ? npos
        : ptr - str;
}

MyString MyString::substr(int startPos, int length) const
{
    assert(startPos >= 0);
    assert(length >= 0);

    return MyString(str + startPos, length);
}

bool MyString::operator==(const MyString& s) const
{
    return strcmp(str, s.str) == 0;
}

bool MyString::operator!=(const MyString& s) const
{
    return strcmp(str, s.str) != 0;
}

bool MyString::operator<(const MyString& s) const
{
    return strcmp(str, s.str) < 0;
}

bool MyString::operator>(const MyString& s) const
{
    return strcmp(str, s.str) > 0;
}

bool MyString::operator<=(const MyString& s) const
{
    return strcmp(str, s.str) <= 0;
}

bool MyString::operator>=(const MyString& s) const
{
    return strcmp(str, s.str) >= 0;
}

MyString MyString::operator+(const MyString& s) const
{
    int newLength = length + s.length;
    char* newStr = new char[newLength + 1];

    strcpy(newStr, str);
    return MyString(strcat(newStr, s.str));

}

MyString::~MyString()
{
    cleanup();
}

void MyString::assign(const char* value)
{
    length = strlen(value);
    str = new char[length + 1];

    strcpy(str, value);
}

void MyString::cleanup()
{
    if(str)
    {
        delete [] str;
    }
}