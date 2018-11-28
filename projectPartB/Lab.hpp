#ifndef LAB_HPP
#define LAB_HPP

#include <iostream>
#include <string>
#include <map>

#include "ioHandiling.hpp"
#include "LinkedList.hpp"

class Lab
{
public:
    Lab();

    //Pr - Takes in an int labSize_ and a string labName_
    //Po - Void function, creates a new Lab object with labSize,
    //     labName, and a Linked List of computer objects
    Lab(int labSize_, std::string labName_);
 
    //Pr - Nothing
    //Po - Void funciton, assigns values to a computer object within the linked list.
    void simulateLogin(ioHandiling::LogFile& log);

    //Pr - Asks for the userID
    //Po - Void function, resets computer object within the linked list.
    void simulateLogoff(int userID, ioHandiling::LogFile& log);

    //Pr - Takes in a recovered string and a logfile object.
    //Po - Void function, parses the linked list 
    void assignToFirstAvailable(std::string line, ioHandiling::LogFile& log);

    //Pr - Nothing
    //Po - Void function, accesses and loops through the linked list.
    void displayLab();

    //Pr - 
    //Po - 
    void searchLab(int userID, int labLoc);

    //Pr - A integer labSize_
    //Po - Void function, modifier for the labSize attribute.
    void assignLabSize(int labSize_);

    //Pr - A string labName_
    //Po - Void fuction, modifier for the labName attribute.
    void assignLabName(std::string labName_);

private:

    //Pr - Nothing
    //Po - Returns a boolean based on if the current lab occupancy is full.
    bool isFull();
    
    //Pr - Lab needs to have been constructued using the default constructor
    //Po - Void function, adds labSize nodes to compuLab
    void fillWithCompuNodes();

    int labOccupancy;
    int labSize;
    std::string labName;

    LinkedList compuLab;
    std::map<int, int> labsLogged;
};

#endif
