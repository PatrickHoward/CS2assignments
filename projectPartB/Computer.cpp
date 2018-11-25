#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>

#include "Computer.hpp"
#include "ioHandiling.hpp"

Computer::Computer()
{
  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

//TODO: Maybe refactor login() and logout() methods to a separate function that creates the logLine?
void Computer::login(int seatLoc_, ioHandiling::LogFile& file)
{
    seatLoc = seatLoc_;
    //Call mkID and assign userID.
    userID = makeID();
    std::cout << "| Assigned user to: " << std::setfill('0') << std::setw(5) << userID << "\n" << std::setfill(' ');

    studentName = ioHandiling::promptString("Please input a name.", 0, 35);

    do
    {
        timeUsed = ioHandiling::promptInt("Please input time used in 15 minute increments.", 15, 60);
    } while(timeUsed % 15 != 0);

    std::cout << "| Assigned " << studentName << " to user# " << userID << ".\n"; 

    writeToLog('I', file);

}

void Computer::login(int seatLoc_, int userID_, std::string studentName_, int timeUsed_, ioHandiling::LogFile& file)
{
    seatLoc = seatLoc_;
    userID = userID_;
    studentName = studentName_;
    timeUsed = timeUsed_;

    std::cout << "| Assigned " << studentName << " into seat " << seatLoc << " \n";

    writeToLog('I', file);    
}

void Computer::logout(ioHandiling::LogFile& file)
{
    userID = -1;
    studentName = "empty";
    timeUsed = 0;
    
    std::cout << "| " << studentName << " has been signed out. \n";

    writeToLog('O', file);
}

int Computer::getID() const
{
    return userID;
}

std::string Computer::getStudentName() const
{
    return studentName;
}

int Computer::getSeatLoc() const
{
    return seatLoc;
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

int Computer::makeID()
{
    return rand()%99999;
}

void Computer::writeToLog(char flag, ioHandiling::LogFile& log)
{
    std::ostringstream logLine;
    logLine << ioHandiling::getTime() << " - " << flag << " - " << userID << " - " <<  timeUsed << " - " << studentName;

    std::string output = logLine.str();

    log.writeLine(output);
}