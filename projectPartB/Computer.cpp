#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>

#include "Computer.hpp"
#include "ioHandiling.hpp"

Computer::Computer()
{
  std::cout << "CompuConstructor called.\n";

  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

//TODO: Maybe refactor login() and logout() methods to a separate function that creates the logLine?
void Computer::login(ioHandiling::LogFile& file)
{
    //Call mkID and assign userID.
    userID = makeID();
    std::cout << "| Assigned user to: " << std::setfill('0') << std::setw(5) << userID << "\n" << std::setfill(' ');

    studentName = ioHandiling::promptString("Please input a name.", 0, 35);

    //And time... Now this can only be set in 15 minute increments...
    do
    {
    timeUsed = ioHandiling::promptInt("Please input time used in 15 minute increments.", 15, 60);
    } while(timeUsed % 15 != 0);

    std::cout << "| Assigned " << studentName << " to user# " << userID << ".\n"; 

    std::ostringstream logLine;
    logLine << ioHandiling::getTime() << " - I - " << userID << " - " <<  timeUsed << " - " << studentName;

    std::string output = logLine.str();

    file.writeLine(output);
}

void Computer::logout(ioHandiling::LogFile& file)
{
    std::cout << "| " << studentName << " has been signed out. \n";

    std::ostringstream logLine;
    logLine << ioHandiling::getTime() << " - O - " << userID << " - " << timeUsed << " - " << studentName;

    std::string output = logLine.str();
    file.writeLine(output);

    userID = -1;
    studentName = "empty";
    timeUsed = 0;
}

int Computer::makeID()
{
    return rand()%99999;
}

int Computer::getID() const
{
    return userID;
}

std::string Computer::getStudentName() const
{
    return studentName;
}

void Computer::assignID(const int userID_)
{
    userID = userID_;
}
void Computer::assignStudentName(std::string& studentName_)
{
    studentName = studentName_;
}

void Computer::assignTime(const int timeUsed_)
{
    timeUsed = timeUsed_;
}