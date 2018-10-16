/*
   COPYRIGHT (C) 2018 Patrick M. Howard (pmh41) All rights reserved.
   MyString class CS assignment
   Author.  Patrick M. Howard
            pmh41@zips.uakron.edu
   Version. 1.12 10.16.2018
   Purpose: string vclass test suite
*/

#include "MyString.hpp"
#include <cstring>
#include <iosfwd>
#include <string>
#include <iostream>
#include <cassert>

// Output
std::ostream& operator<<(std::ostream&, MyString const&);

// Encapsulate all of the String tests.

// Encapsulate all of the String tests.
struct Test_string
{
  void default_ctor()
  {
    // Check the default contructor.
    MyString s;
    assert(s.empty());
  }

  void string_ctor()
  {
    const char* str = "hello";
    MyString s = str;
    assert(s.data() != str);
    assert(strcmp(s.data(), str) == 0);
  }


  void copy_ctor()
  {
    MyString s1 = "hello";
    MyString s2 = s1;
    assert(strcmp(s1.data(), s2.data()) == 0);
  }

  void copy_assign()
  {
    MyString s1 = "hello";
    MyString s2;
    s2 = s1;
    assert(strcmp(s1.data(), s2.data()) == 0);
  }

  void string_assign()
  {
    MyString s;
    s = "hello";
    assert(!strcmp(s.data(), "hello"));
  }

  void self_assign()
  {
    MyString s1 = "hello";
    s1 = s1;
  }

  void empty()
  {
    MyString const s1;
    assert(s1.empty());
    MyString const s2 = "";
    assert(s2.empty());
  }

  void access()
  {
    MyString s1 = "hello";
    s1[0] = 'a';
    assert(s1[0] == 'a');

    MyString const s2 = "test";
    assert(s2[0] == 't');

//    assert(s1[-1]);
//    assert(s2[-1]);
  }

  void find()
  {
    MyString const s1 = "abcdef";
    assert(s1.find('c') == 2);
    assert(s1.find('z') == s1.npos);
  }

  void substr()
  {
    MyString const s1 = "abcdef";
    MyString s2 = s1.substr(0, 3);
    MyString s3 = s1.substr(3, 3);
    assert (s2 == "abc");
    assert (s3 == "def");
  }

  void equality()
  {
    MyString const s1 = "hello";
    MyString const s2 = "goodbye";
    assert(s1 == s1);
    assert(s1 != s2);
  }

  void ordering()
  {
    MyString s1 = "abc";
    MyString s2 = "def";
    assert(s1 < s2);
    assert(s2 > s1);
    assert(s1 <= s1);
    assert(s1 >= s1);
  }

  void concatenation()
  {
    MyString s1 = "abc";
    MyString s2 = "def";
    MyString s3 = s1 + s2;
    MyString s4 = "abcdef";
    assert(s3 == s4);
  }

  void self_concatenation()
  {
    MyString s1 = "abc";
    s1 += s1;
    MyString s2 = "abcabc";
    assert(s1 == s2);
  }

  // The assert test runner for this test class.
  void run()
  {
    default_ctor();
    string_ctor();
    copy_assign();
    string_assign();
    self_assign();
    empty();
    access();
    find();
    substr();
    equality();
    ordering();
    concatenation();
    self_concatenation();
  }
};


int
main()
{
  Test_string test;
  test.run();
  return 0;
}
