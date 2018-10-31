#include "Lab.hpp"
#include "ioHandiling.hpp"

Lab::Lab()
{
    labSize = 0;
    labName = "uni name";
}

Lab::Lab(int labSize_, std::string labName_)
    : labSize(labSize_),
    labName(labName_)
{
    labOccupancy = 0;
}

// Computer search (int userID)
// {}

void Lab::simulateLogin(ioHandiling::LogFile& log)
{
    if (labOccupancy >= labSize)
    {
        std::cout << "| Lab occupancy is full at this time, please try again later.\n";
        return;
    }
    int seatSelection = ioHandiling::promptInt("Please select a seat assignment.", 1, labSize);

    
    //TODO: Use the search method and check to see if the desired lab is occupied.
    //Find the appropriate spot in a linked list and call that computer object's login method.
    
}

void Lab::simulateLogoff(int userID, ioHandiling::LogFile& log)
{
    do
    {
        //Iterate through the linked list        

    }while(1);

}

void Lab::displayLab()
{
    //Loop through every node in the LinkedList
}

void Lab::assignLabSize(int labSize_)
{
    labSize = labSize_;
}

void Lab::assignLabName(std::string labName_)
{
    labName = labName_;
}