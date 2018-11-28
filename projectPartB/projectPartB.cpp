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
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 4, 17, 55, 37};

//Universities currently under constract.
const std::string UNIVERSITYNAMES[NUMLABS] = {
                                              "The University of Michigan", 
                                              "The University of Pittsburgh", 
                                              "Stanford University",
                                              "Arizona State University", 
                                              "North Texas State University", 
                                              "The University of Alabama, Huntsville", 
                                              "Princeton University", 
                                              "Duquesne University"
                                            };

std::string logfile = "labTrac_log.txt";

struct Menu
{

    //Pr - 
    //Po - 
    void printHeader(); //Prints the header

    //Pr - 
    //Po - 
    void printLabs(); //Prints the available labs to select from.

    //Pr - 
    //Po - 
    void printMenu(); //Prints the menu to select from.

    //Pr - 
    //Po - 
    void startupTimestamp(ioHandiling::LogFile& log); 

    //Pr - 
    //Po - 
    void printStartup(); //Prints the top three functions, respectively.

    //Pr - 
    //Po - 
    void modifyLab(int selection, Lab labArray[], ioHandiling::LogFile& file); //Performs the logic of each menu selection.

    //Pr - 
    //Po - 
    int promptUserId();

    //Pr - 
    //Po - 
    int promptUniversitySelection();

    //Pr - 
    //Po - 
    void simulateLogin(Lab labArray[], ioHandiling::LogFile& log);

    //Pr - 
    //Po - 
    void simulateLogoff(Lab labArray[], ioHandiling::LogFile& log);

    //Pr - 
    //Po - 
    void searchLab(Lab labArray[], ioHandiling::LogFile& log);

    //Pr - 
    //Po - 
    void displayLab(Lab labArray[]);

    //Pr - Takes in the LabArray and the logFile object.
    //Po - Recovers a user based on their ID number.
    void recoverUser(Lab labArray[], ioHandiling::LogFile& log);

    //Pr - Takes in a logFile object.
    //Po - Returns a bool causing the while loop to break, exiting the program. 
    bool quitLabTrac(ioHandiling::LogFile& file);
};

enum class MenuOption
{
    login = 1,
    logoff = 2,
    search = 3,
    displayLab = 4,
    recover = 5,
    quit = 6,
};

int main()
{
    srand(time(0)); //Setting the seed for rand

    Menu instance; 
    instance.printStartup();

    ioHandiling::LogFile activityTracker(logfile);
    //instance.startupTimestamp(activityTracker); //For logging purposes, uncomment for startup.

    bool active = true;

    Lab availableLabs[NUMLABS];
    for(int i = 0; i < NUMLABS; ++i)
    {
        availableLabs[i].assignLabName(UNIVERSITYNAMES[i]);
        availableLabs[i].assignLabSize(LABSIZES[i]);
        availableLabs[i].fillWithCompuNodes();
    }

    while(active)
    {
        MenuOption selection = (MenuOption)ioHandiling::promptInt("Please select a menu item. ", 1, 6);

        switch(selection)
        {
            case MenuOption::login:
                instance.simulateLogin(availableLabs, activityTracker);
                break;

            case MenuOption::logoff:
                instance.simulateLogoff(availableLabs, activityTracker);
                break;

            case MenuOption::search:
                instance.searchLab(availableLabs, activityTracker);
                break;

            case MenuOption::displayLab:
                instance.displayLab(availableLabs);
                break;

            case MenuOption::recover:
                instance.recoverUser(availableLabs, activityTracker);
                break;

            case MenuOption::quit:
                active = instance.quitLabTrac(activityTracker);
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
    std::string menuOptions[6] =
    {
        "Simulate Login",
        "Simulate Logoff", 
        "Search",
        "Display Lab",
        "Recover User",
        "Quit"
    };

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
    //file.writeLine("Exited LabTrac2 on " + ioHandiling::getTime());
    return false;
}

int Menu::promptUserId()
{
    return ioHandiling::promptInt("Please input a user ID.", 1, 99999);
}

int Menu::promptUniversitySelection()
{
    return ioHandiling::promptInt("Please select a lab.", 1, NUMLABS);
}

void Menu::simulateLogin(Lab labArray[], ioHandiling::LogFile& log)
{
    int uniSelection = promptUniversitySelection();
    std::cout << "| Selected " << UNIVERSITYNAMES[uniSelection - 1] << "\n";
    labArray[uniSelection].simulateLogin(log);
}

void Menu::simulateLogoff(Lab labArray[], ioHandiling::LogFile& log)
{
    int userID = promptUserId();
    for(int i = 0; i < NUMLABS; i++)
    {
        labArray[i].simulateLogoff(userID,log);
    }
}

void Menu::searchLab(Lab labArray[], ioHandiling::LogFile& log)
{
    int userID = promptUserId();
    for(int i = 0; i < NUMLABS; i++)
    {
        labArray[i].searchLab(userID, i+1);
    }
}

void Menu::displayLab(Lab labArray[])
{ 
    int uniSelection = promptUniversitySelection();
    labArray[uniSelection - 1].displayLab();
}

void Menu::recoverUser(Lab labArray[], ioHandiling::LogFile& log)
{
    int userID = promptUserId();
    int uniSelection = promptUniversitySelection();

    int recoveredID = -1;
    std::string currentLine;

    while (recoveredID != userID)
    {
        currentLine = log.pullLine(0);

        if(currentLine == "eof")
        {
            break;
        }
        if(currentLine.length() > 27)
        {
            recoveredID = stoi(currentLine.substr(27, 5));
        }
    }

    if (recoveredID == userID)
    {
        
        labArray[uniSelection - 1].assignToFirstAvailable(currentLine, log);
    }
}