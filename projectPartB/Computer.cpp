#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<iomanip>

#include "Computer.hpp"

Computer::Computer()
{
  
  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

void Computer::login()
{
  //Call mkID and assign userID.
  userID = mkID();
  std::cout << "| Assigned user to: " << std::setfill('0') << std::setw(5) << userID << "\n" << std::setfill(' ');


  //Now to assign the name...  
  bool invalidInput = true; //Unlike the American judicial system, invalid until proven valid.
  while(invalidInput)//Check to make sure the name is less than 35 characters 
  {

    std::cout << "| Please input a name (max 35 chars) > ";
    std::getline(std::cin, studentName);

    if(studentName.length() > 35 || studentName.length() == 0)
    { 
      //Input is deemed invalid, clean the buffer and try again.
      std::cout << "| Invalid input, please try again.\n";
      scrub(std::cin);
    }
    else
    {
      //Valid input, set invalidInput to true and move on.
      invalidInput = false;
    }  
  }
  
  //And time... Now this can only be set in 15 minute increments...
  invalidInput = true; //I'm recycling this...
  while(invalidInput)
  { 
    std::cout << "| Please input time used (15/30/45/60) > ";
    std::cin >> timeUsed;
    
    if(std::cin.fail() || timeUsed > 60 || timeUsed % 15 != 0)
    {
      //Invalid is deemed invalid, clean the buffer and try agian. 
      std::cout << "| Invalid input, please try again.\n";
     
      scrub(std::cin);
    }
    else
    {
      //Valid input, set invalidInput to false and move on.
      invalidInput = false;
    } 
    std::cout << "| Assigned " << studentName << " to user# " << userID << ".\n";
  } 
}

void Computer::logout()
{
  std::cout << "| " << studentName << " has been signed out. \n";

  //Reassign initial values.
  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

int Computer::mkID()
{return rand()%99999;}

int Computer::getID()
{return userID;}

std::string Computer::getStudentName()
{return studentName;}

void Computer::assignID(int id)
{userID = id;}

void Computer::assignStudentName(std::string name)
{studentName = name;}

void Computer::assignTime(int time)
{timeUsed = time;  }