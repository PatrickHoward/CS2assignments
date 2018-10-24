/*
  PROJECT PART B - Patrick M. Howard (pmh41) - LabTrac
  Copyright 2018, all rights reserved. 
  pmh41@zips.uakron.edu
  ver 0.34 9.28.2018
  Purpose: This program manages computer labs for several different universities. It can sign on, sign off users and keep track of 
           where they are in the system. 
*/

#include <string>
#include <iostream>

#include <cstdlib>
#include <ctime>

#include "ioHandiling.hpp"
#include "Lab.hpp"

//Global Constants
//Number of computer Labs
const int NUMLABS = 8;
//Number of computers in each lab;
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};

//Universities currently under constract.
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", 
                                              "Stanford University", "Arizona State University", "North Texas State University", 
                                              "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};

struct Menu
{
  void printHeader();

  void printLabs();

  void printMenu();

  void printStartup();

  void 

  bool quitLabTrac();

};



int main()
{
  srand(time(0)); //Setting the seed for rand

  Menu instance; 
  instance.printStartup();  

  bool active = true;
  int selection = 0;

  Lab availableLabs[NUMLABS];
  for(int i = 0; i < NUMLABS; ++i)
  {
    availableLabs[i].assignLabName(UNIVERSITYNAMES[i]);
    availableLabs[i].assignLabSize(LABSIZES[i]);
  }

  while(active)
  {
    selection = ioHandiling::promptInt("Please select a menu item. ", 1, 4);
    switch(selection)
    {
      //Option 1:
      case 1: 
        break;

      //Option 2:
      case 2:
        break;

      //Option 3: 
      case 3:
        break;
      
      //Option 4: logout
      case 4: active = instance.quitLabTrac();
        break;

    }

  }
} 

void Menu::printHeader()
{
  std::cout << "|-- LabTrac 2 - Student Computer Lab Tracking System --|\n"
       << "|-- Created by Patrick M. Howard - For education use --|\n";

}

void Menu::printLabs()
{
  for(int i = 0; i < NUMLABS; ++i)
  {
    std::cout << "| Lab #" << i+1 << " for " << UNIVERSITYNAMES[i] << "\n";
  }
}

void Menu::printMenu()
{
  std::string menuOptions[5] = {"Simulate Login", "Simulate Logoff", "Search", "Display Lab", "Quit"};
  
  std::cout << "| MAIN MENU\n";
  for(int i = 0; i < 5; ++i)
  {
    std::cout << "| " << i+1 << ") " << menuOptions[i] << "\n";
  } 
}

void Menu::printStartup()
{
  printHeader();
  printLabs();
  printMenu();
}

bool Menu::quitLabTrac()
{
  std::cout << "|-- Now exiting, goodbye!\n" << "|-- LabTrac 2 - By Patrick M. Howard\n";
  return false;
}


