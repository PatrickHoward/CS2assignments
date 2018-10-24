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
        if (labOccupancy >= labSize)
        {
            std::cout << "| Lab occupancy is full at this time, please try again later.\n";
        }
        int seatSelection = ioHandiling::promptInt("Please select a seat assignment.", 1, labSize);
        //TODO: Use the search method and check to see if the desired lab is occupied.
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
        //Loop through every node in the LinkedList
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