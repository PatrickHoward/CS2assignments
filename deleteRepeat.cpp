/*
  Computer Science II - Assignment A - Patrick M. Howard <pmh41@zips.uakron.edu>
  The University of Akron
  
  Desc: This program takes an array of characters and returns another array of characters
  	that are not repeated in the input.   
    
  Assignment due date - 9/12/2018
  Copyright 2018, all rights reserved

*/
#include<iostream>
#include<memory> //For unique pointers 

std::unique_ptr<char[]> deleteRepeat(char[], int&);
//Pre:  An array of characters is taken in, and a empty integer is passed in by reference 
//      (so that the number of unique characters can be printed in the main function.
//Post: An array of unique characters is returned via a std::unique_ptr<char[]>.

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

  int numOfUniques;

  //Print the original array...
  std::cout << "Here is the test case: \n";
  for(int i = 0; i < SIZE-1; i++)
  {
    std::cout << originalArray[i] << ", "; //Print each element separated by a comma and a space.
  }
  std::cout << originalArray[SIZE-1] << '\n';
  
  std::unique_ptr<char[]> noRepeats = deleteRepeat(originalArray, numOfUniques );
  
  std::cout << "And here are the unique characters: \n";
  for(int i = 0; i < numOfUniques-1; i++)
  {
    std::cout << noRepeats[i] << ", ";
  
  }
  std::cout << noRepeats[numOfUniques-1];
  std::cout << "\n There are " << numOfUniques << " in the given sequence of chars\n";

  return 0;
}

std::unique_ptr<char[]> deleteRepeat(char originalLetters[], int& arrSize)
{
  int nUniqueChars = 0; //Number of unique characters that exists in originalLetters[]
  char highestChar ='-'; //The highest character that exists alphabetically.

  //Run the first loop to find the quantity of unique characters.
  for(int i = 0; i < SIZE; i++)
  {
    if(originalLetters[i] > highestChar )//If the character comes after the highest character
    { 
      nUniqueChars++;
      highestChar=originalLetters[i];
    }
  }

  std::unique_ptr<char[]> uniqueChars(new char[nUniqueChars]);//Creates a new dynamically allocated array that is the size of nUniqueChars 

  highestChar = '-'; //Reset the value of highestChar. 

  //Run the second loop to find the first occurance each unique character.
  for(int i = 0; i < nUniqueChars; i++)
  {
    for(int j = 0; j < SIZE; j++)
    {
      if(originalLetters[j] > highestChar)
      {
        highestChar = originalLetters[j];
	uniqueChars[i] = originalLetters[j];
	break;
      }
    }
  }   
   
  arrSize = nUniqueChars; 
  return uniqueChars;
 

}
