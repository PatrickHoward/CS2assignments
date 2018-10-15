#include<iostream>

#include "Menu.hpp"

void Menu::printHeader()
{
  std::cout << std::setw(60) << " ___________________________________________________________\n"
            << "|----------------------------------------------------------|\n"
            << "|                         LabTrac                          |\n"
            << "|            Student Computer Lab Tracking System          |\n"
            << "|__________________________________________________________|\n"
            << "|\n";
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