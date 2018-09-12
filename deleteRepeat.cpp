/*
  Computer Science II - Assignment A - Patrick M. Howard <pmh41@zips.uakron.edu>
  The University of Akron

  Assignment due date - 9/12/2018
  Copyright 2018, all rights reserved

*/
#include<iostream>
#include<memory> //For unique pointers 
char* deleteRepeat(char[]);
const int SIZE = 10;

int main()
{
  char originalArray[SIZE];
  originalArray [0] = 'a';
  originalArray [1] = 'b';
  originalArray [2] = 'b';
  originalArray [3] = 'c';
  originalArray [4] = 'a';
  originalArray [5] = 'c';
  originalArray [6] = 'a';
  originalArray [7] = 'c';
  originalArray [8] = 'b';
  originalArray [9] = 'c';

  //Print the original array...
  std::cout << "Here is the test case: " << std::endl;
  for(int i = 0; i < SIZE; i++)
  {
    std::cout << originalArray[i] << ", "; //Print each element separated by a comma and a space.
  }
  std::cout << std::endl << std::endl;

  char* noRepeats = deleteRepeat(originalArray);

  return 0;
}

char* deleteRepeat(char originalLetters[] )
{
  //Create a new dynamic array, using constant SIZE to determine initial size.
  char* uniqueChars;
  uniqueChars = new char[SIZE];
  
   
  
  return uniqueChars;
 

}
