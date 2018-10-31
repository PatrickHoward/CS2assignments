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
#include "ioHandiling.hpp"


//Global Constants
//Number of computer Labs
const int NUMLABS = 8;
//Number of computers in each lab;
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 4, 17, 55, 37};

//Universities currently under constract.
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", 
                                              "Stanford University", "Arizona State University", "North Texas State University", 
                                              "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};

std::string logfile = "labTrac_log.txt";

struct Menu
{
    void printHeader(); //Prints the header

    void printLabs(); //Prints the available labs to select from.

    void printMenu(); //Prints the menu to select from.

    void startupTimestamp(ioHandiling::LogFile& log); 

    void printStartup(); //Prints the top three functions, respectively.

    void modifyLab(int selection, Lab labArray[], ioHandiling::LogFile& file); //Performs the logic of each menu selection.

    bool quitLabTrac(ioHandiling::LogFile& file); //Exits the program.
};

int main()
{
    srand(time(0)); //Setting the seed for rand

    Menu instance; 
    instance.printStartup();

    ioHandiling::LogFile activityTracker(logfile);
    instance.startupTimestamp(activityTracker);

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
        selection = ioHandiling::promptInt("Please select a menu item. ", 1, 6);
        switch(selection)
        {
        //Option 1: Login
        case 1: instance.modifyLab(1, availableLabs, activityTracker);
        break;

        //Option 2: Logout
        case 2: instance.modifyLab(2, availableLabs, activityTracker);
        break;

        //Option 3: Search
        case 3: instance.modifyLab(3, availableLabs, activityTracker);
        break;

        //Option 4: Display Lab
        case 4: instance.modifyLab(4, availableLabs, activityTracker);
        break;

        //Option 5: Recover User
        case 5: instance.modifyLab(5, availableLabs, activityTracker);
        break;
        //Option 6: Quit program
        case 6: active = instance.quitLabTrac(activityTracker);
        break;
        }
    }
} 

void Menu::printHeader()
{
std::cout << "\n\n|-- LabTrac 2 - Student Computer Lab Tracking System --|\n"
          << "|-- Created by Patrick M. Howard - For education use --|\n|\n";

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
    std::string menuOptions[6] = {"Simulate Login", "Simulate Logoff", 
                                  "Search", "Display Lab", "Recover User",
                                  "Quit"};

    std::cout << "|\n| MAIN MENU\n";
    for(int i = 0; i < 6; ++i)
    {
        std::cout << "| " << i+1 << ") " << menuOptions[i] << "\n";

    }

    std::cout << "|\n"; 
}

void Menu::startupTimestamp(ioHandiling::LogFile& file)
{
    file.writeLine("LabTrac2 Started on " + ioHandiling::getTime());
}

void Menu::printStartup()
{
    printHeader();
    printLabs();
    printMenu();
}

bool Menu::quitLabTrac(ioHandiling::LogFile& file)
{
    std::cout << "|-- Now exiting, goodbye!\n" << "|-- LabTrac 2 - By Patrick M. Howard\n";
    file.writeLine("Exited LabTrac2 on " + ioHandiling::getTime());
    return false;
}

void Menu::modifyLab(int selection, Lab labArray[], ioHandiling::LogFile& log)
{
    int uniSelection;
    int userID;

    //Options 1 (Login) and 4 (display lab) ask for
    if(selection == 1 || selection == 4)
    { 
        uniSelection = ioHandiling::promptInt("Please select a lab.", 1, NUMLABS);
    }
    else if (selection == 2 || selection == 3 || selection == 5)
    {
        userID = ioHandiling::promptInt("Please input a user ID.", 1, 99999);   
    }

    if(selection == 1)
    {
        std::cout << "| Selected " << UNIVERSITYNAMES[uniSelection] << "\n";
        labArray[uniSelection].simulateLogin(log);
    }
    else if(selection == 2)
    {
        for(int i = 0; i < NUMLABS; i++)
        {
            //labArray[i].simulateLogout(userID);
        }
    }
    else if(selection == 3)
    {


    }
    else if(selection == 4)
    {

    }

    std::cout << "| \n";
}
