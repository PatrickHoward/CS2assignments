#pragma once

#include <iostream>
#include <string>

#include "ioHandiling.hpp"

class Lab
{
public:
    Lab()
    {
        labSize = 0;
        labName = "uni name";
    }

    Lab(int labSize_, std::string labName_)
        : labSize(labSize_),
        labName(labName_)
    {
        labOccupancy = 0;
    }

    // Computer search (int userID);
 
    void simulateLogin()
    {
        int seatSelection = ioHandiling::promptInt("Please select a seat assignment.", 1, labSize);
        //Find the appropriate spot in a linked list and call that computer object's login method.
    }
 
    void simulateLogoff(int userID)
    {
        do
        {
            //Iterate through the linked list        

        }while(1);

    }

    void displayLab()
    {

    }

    void assignLabSize(int labSize_)
    {
        labSize = labSize_;
    }

    void assignLabName(std::string labName_)
    {
        labName = labName_;
    }

private:
    int labOccupancy;
    int labSize;
    std::string labName;
    //LinkedList compuLab
};