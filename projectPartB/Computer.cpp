#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>

#include "Computer.hpp"
#include "ioHandiling.hpp"

Computer::Computer()
{
  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

void Computer::login()
{
  //Call mkID and assign userID.
  userID = makeID();
  std::cout << "| Assigned user to: " << std::setfill('0') << std::setw(5) << userID << "\n" << std::setfill(' ');
  
  
  //And time... Now this can only be set in 15 minute increments...
  do
  {
    timeUsed = ioHandiling::promptInt("Please input time used in 15 minute increments.", 15, 60);
  } while(timeUsed % 15 != 0);

  std::cout << "| Assigned " << studentName << " to user# " << userID << ".\n"; 
}

void Computer::logout()
{
  std::cout << "| " << studentName << " has been signed out. \n";

  //Reassign initial values.
  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

int Computer::makeID()
{
  return rand()%99999;
}

int Computer::getID()
{
  return userID;
}

std::string Computer::getStudentName()
{
  return studentName;
}

void Computer::assignID(int userID_)
{
  userID = userID_;
}
void Computer::assignStudentName(std::string studentName_)
{
  studentName = studentName_;
}


void Computer::assignTime(int timeUsed_)
{
  timeUsed = timeUsed_;
}