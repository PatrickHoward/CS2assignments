#pragma once

#include <iostream>
#include <string>

#include "ioHandiling.hpp"

class Lab
{
public:
    Lab();

    //Pr - Takes in an int labSize_ and a string labName_
    //Po - Void function, creates a new Lab object with labSize,
    //     labName, and a Linked List of computer objects
    Lab(int labSize_, std::string labName_);

    // Computer search (int userID);
 
    //Pr - Nothing
    //Po - Void funciton, assigns values to a computer object within the linked list.
    void simulateLogin();

    //Pr - Asks for the userID
    //Po - Void function, resets computer object within the linked list.
    void simulateLogoff(int userID);

    //Pr - Nothing
    //Po - Void function, accesses and loops through the linked list.
    void displayLab();

    //Pr - A integer labSize_
    //Po - Void function, modifier for the labSize attribute.
    void assignLabSize(int labSize_);

    //Pr - A string labName_
    //Po - Void fuction, modifier for the labName attribute.
    void assignLabName(std::string labName_);

private:
    int labOccupancy;
    int labSize;
    std::string labName;
    //LinkedList compuLab
};