#include<iostream>
#include<ctime>//For making the seed
#include<cstdlib>//For 
#include<iomanip>//For manipulating the input! Yay!
#include<string>//For strings (wow)
/*
  PROJECT PART A - Patrick M. Howard (pmh41) - LabTrac
  Copyright 2018, all rights reserved. 
  pmh41@zips.uakron.edu
  ver 0.34 9.28.2018
  Purpose: 
*/




//Global Constants
//Number of computer Labs
const int NUMLABS = 8;
//Number of computers in each lab;
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};

//Universities currently under constract.
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University", "Arizona State University", "North Texas State University", "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};

//Prints the header or the menu.
void printHeader();
void printMenu();

class Computer
{
  public:
    //Constructors
    Computer(); //Default constructor
    Computer(std::string&, int); //Specific constructor, initializes with name and timeUsed
    
    //The login and logout functions reassign 
    void login();
    void logout();
    
    int mkID();
  private:
    int userID; //Randomly generates 5 digit ID numbers upon login.
    std::string studentName; //Maximum 35 characters
    int timeUsed; //Should only be in increments of 15 minutes with an hour max.

};

Computer::Computer()
{
  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

void Computer::login()
{
  //Call mkID
  
  
}

void Computer::logout()
{

}

int mkID()
{
  return rand()&9999;
}


int main()
{ 
  srand(time(NULL)); //Set the seed for random IDs.
  printHeader(); //Print the header upon startup.
  std::cout << "| Welcome to LabTrac, here are a list of the available\n| computer labs\n\n";

  //Print all available labs
  for(int i = 0; i < NUMLABS-1; ++i)
  {
    std::cout << "| Lab #" << i << " for " << UNIVERSITYNAMES[i] << "\n";
  }
  std::cout << "| Lab #" << NUMLABS << " for " << UNIVERSITYNAMES[NUMLABS - 1] << "\n\n";
  
  printMenu();
}

void printHeader()
{
  std::cout << std::setw(60) << " ___________________________________________________________\n"
            << "|----------------------------------------------------------|\n"
            << "|                         LabTrac                          |\n"
            << "|            Student Computer Lab Tracking System          |\n"
            << "|__________________________________________________________|\n"
            << "|\n";
}

void printMenu()
{
  std::string menuOptions[5] = {"Simulate Login", "Simulate Logoff", "Search", "Display Lab", "Quit"};
  
  std::cout << "| MAIN MENU\n";
  for(int i = 0; i < 5; ++i)
  {
    std::cout << "| " << i << ") " << menuOptions[i] << "\n";
  }

  
}
