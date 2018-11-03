/*
   COPYRIGHT (C) 2018 Patirck M. Howard (pmh41) All rights reserved.
   CS assignment
   Author.  Patrick M. Howard
            pmh41@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: string vector class test suite
*/

#include "MyStringVector.hpp"

#include <string>
#include <algorithm>
#include <iostream>
#include <cassert>


namespace
{

template<typename I1, typename I2>
inline bool
my_equal(I1 first1, I1 limit1, I2 first2, I2 limit2)
{
  while (first1 != limit1 && first2 != limit2) {
    if (*first1 != *first2)
      return false;
    ++first1;
    ++first2;
  }
  return first1 == limit1 && first2 == limit2;
}

}


// Encapsulate all of the string vector tests.
struct Test_MyStringVector
{
  void default_ctor()
  {
    MyStringVector v;
    assert(v.empty());
  }

  void copy_ctor()
  {
    MyStringVector v1 {"a", "b", "c"};
    MyStringVector v2 = v1;
    assert(v1 == v2);
  }

  void copy_assign()
  {
    MyStringVector v1 {"a", "b", "c"};
    MyStringVector v2;
    v2 = v1;
    assert(v1 == v2);
  }

  void self_assign()
  {
    MyStringVector v {"a", "b", "c"};
    v = v;
  }

  void empty()
  {
    MyStringVector const v1;
    MyStringVector const v2 {"a"};
    assert(v1.empty());
    assert(!v2.empty());
  }

  void size()
  {
    MyStringVector const v1;
    MyStringVector const v2 {"a"};
    assert(v1.size() == 0);
    assert(v2.size() == 1);
  }

  void reserve()
  {
    MyStringVector v;
    MyStringVector const& cv = v;
    assert(cv.capacity() == 0);
    v.reserve(20);
    assert(cv.capacity() >= 20);
    v.reserve(5);
    assert(cv.capacity() >= 20);
  }

  void resize()
  {
    MyStringVector v1 {"", "", ""};
    MyStringVector v2;

    v2.resize(3);
    assert(v1.size() == 3);
    assert(v1 == v2);
  }

  void clear()
  {
    MyStringVector v {"a", "b", "c"};
    v.clear();
    assert(v.empty());
    assert(v.capacity() != 0);
  }

  void push_back()
  {
    MyStringVector v;
    v.push_back("a");
    assert(v.size() == 1);
    assert(v[0] == "a");
  }

  void pop_back()
  {
    MyStringVector v1 {"a", "b", "c"};
    v1.pop_back();
    assert(v1.size() == 2);

    MyStringVector v2;
    check_assertion(v2.pop_back());
  }

  void access()
  {
    MyStringVector v {"a", "b", "c"};
    MyStringVector const& cv = v;

    assert(v[0] == "a");
    assert(cv[0] == "a");

    v[0] = "q";
    assert(v[0] == "q");

  }

  void iterators()
  {
    MyStringVector v {"a", "b", "c"};
    MyStringVector const& cv = v;
    using I = MyStringVector::iterator;
    using C = MyStringVector::const_iterator;
    I first1 = v.begin(), limit1 = v.end();
    C first2 = cv.begin(), limit2 = cv.end();
    assert(my_equal(first1, limit1, first2, limit2));
  }

  void ordering()
  {
    MyStringVector const v1 {"a", "b", "c"};
    MyStringVector const v2 {"d", "e", "f"};

    assert(v1 < v2);
    assert(v2 > v1);
    assert(v1 <= v1);
    assert(v2 >= v1);
  }

  // The test runner for this test class.
  void run()
  {
    default_ctor();
    copy_assign();
    self_assign();
    empty();
    size();
    reserve();
    resize();
    clear();
    push_back();
    pop_back();
    access();
    iterators();
    ordering();
  }
};


int
main()
{
  Test_MyStringVector test;
  test.run();
  return 0;
}
