#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>

#include "Computer.hpp"
#include "ioHandiling.hpp"

Computer::Computer(int labLoc_)
	:labLoc(labLoc_)
{
  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

//TODO: Maybe refactor login() and logout() methods to a separate function that creates the logLine?
Computer* Computer::login(ioHandiling::LogFile& file)
{
    if(isOccupied())
    {
        return nullptr;
    }

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
    
    return this*;
}

Computer* Computer::login(int userID_, std::string studentName_, int timeUsed_, ioHandiling::LogFile& file)
{
    if(isOccupied())
    {
        return;
    }

    userID = userID_;
    studentName = studentName_;
    timeUsed = timeUsed_;

    std::cout << "| Assigned " << studentName << " into seat " << seatLoc << " \n";

    writeToLog('I', file);
    
    return this*;
}

void Computer::logout(ioHandiling::LogFile& file)
{   
    std::cout << "| " << studentName << " has been signed out. \n";

    writeToLog('O', file);

    userID = -1;
    studentName = "empty";
    timeUsed = 0;
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

void Computer::assignTime(int timeUsed_)
{
    timeUsed = timeUsed_;
}

void Computer::assignSeatLocation(int seatLoc_)
{
    seatLoc = seatLoc_;
}

int Computer::makeID()
{
    return rand()%99999;
}

void Computer::writeToLog(char flag, ioHandiling::LogFile& log)
{
    std::ostringstream logLine;
    logLine << ioHandiling::getTime() << " - " << flag << " - " << userID << " - " <<  timeUsed << " - " << studentName << "\n";

    std::string output = logLine.str();

    log.writeLine(output);
}

bool Computer::isOccupied()
{
    if(userID != -1)
    {
        std::cout << "| !! - Seat already occupied, please select another. - !!\n";
        return true;
    }

    return false;
}