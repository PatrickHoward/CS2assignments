/*
  Computer Science II - Assignment A - Patrick M. Howard <pmh41@zips.uakron.edu>
  The University of Akron

  Assignment due date - 9/12/2018
  Copyright 2018, all rights reserved

*/
#include<iostream>
#include<memory> //For unique pointers

std::unique_ptr<char[]> deleteRepeat(char[]);
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

  std::unique_ptr<char[]> noRepeats = deleteRepeat(originalArray);

  return 0;
}

std::unique_ptr<char[]> deleteRepeat(char originalLetters[] )
{
  //Create a new dynamic array, using constant SIZE to determine initial size.
  std::unique_ptr<char[]> uniqueChars;
  uniqueChars = new  char[SIZE];
  
  //Append the first original letter to the dyanmic array.
  int nUniqueChars = 1;
  uniqueChars[0] = originalLetters[0];
  
  //The variable nUniqueChars defines the number and the last position in the dynamic array.

  for(int i = 0; i <= nUniqueChars; ++i) //For every unique letter encountered...
  {
   for(int j = 0; j < SIZE; ++j) //For every element in the array passed into the function.
   {
     if(originalLetters[j] != uniqueChars[i])
     {
       //Append and increment the value of nUniqueChars
       uniqueChars[nUniqueChars] = originalLetters[j];
       nUniqueChars++;
     }
     else
     {
       //Movo.
     }
   } 
  }
  
  return uniqueChars;
 

}
