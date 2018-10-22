#include <iostream>
#include <string>

#include "Menu.hpp"

using namespace std;

void Menu::printHeader()
{
  cout << "|-- LabTrac 2 - Student Computer Lab Tracking System --|\n"
       << "|-- Created by Patrick M. Howard - For education use --|\n";

}

void Menu::printLabs(const string labs[], int numLabs)
{
  for(int i = 0; i < numLabs; ++i)
  {
    std::cout << "| Lab #" << i+1 << " for " << labs[i] << "\n";
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