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

    MyString();

    MyString(const char* literal);

    MyString(const char* literal, int n);

    MyString(const MyString& s);

    void operator=(const char* literal);

    void operator=(const MyString& s);

    void operator+=(const MyString& s);

    bool empty() const;

    std::size_t size() const;

    char& operator[](std::size_t index) const;

    const char* data() const;

    std::size_t find(char c) const;

    MyString substr(int startPos, int length) const;

    bool operator==(const MyString& s) const;

    bool operator!=(const MyString& s) const;

    bool operator<(const MyString& s) const;

    bool operator>(const MyString& s) const;

    bool operator<=(const MyString& s) const;

    bool operator>=(const MyString& s) const;

    MyString operator+(const MyString& s) const;

    ~MyString();


private:
    void assign(const char* value);
    
    void cleanup();

    std::size_t length;
    char* str;

};