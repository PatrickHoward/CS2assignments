#include <sstream>

#include "Lab.hpp"
#include "ioHandiling.hpp"



Lab::Lab()
{
    labSize = 0;
    labOccupancy = 0;
    labName = "uni name";
}

Lab::Lab(int labSize_, std::string labName_)
    : labSize(labSize_),
    labName(labName_)
{
    labOccupancy = 0;
    fillWithCompuNodes();
}

void Lab::simulateLogin(ioHandiling::LogFile& log)
{
    if (labOccupancy >= labSize)
    {
        std::cout << "| Lab occupancy is full at this time, please try again later.\n";
        return;
    }
    int seatSelection = ioHandiling::promptInt("Please select a seat assignment.", 1, labSize);
    CompuNode* selectedComp;

    selectedComp = compuLab.goToNComp(seatSelection);
    selectedComp->data.login(seatSelection, log);
}

void Lab::simulateLogoff(int userID, ioHandiling::LogFile& log)
{
    CompuNode* selectedComp;
    selectedComp = compuLab.findComputerByID(userID);
    if(selectedComp->data.getID() != -1)
    {
        selectedComp->data.logout(log);
    }
}

void Lab::searchLab(int userID, int labLoc)
{
    CompuNode* selectedComp;
    int seatLocation = 0;

    selectedComp = compuLab.findComputerByID(userID);
    if(selectedComp->data.getID() == userID)
    {
        std::cout << "| Found " << selectedComp->data.getStudentName() << " in Lab " << labLoc 
                  << " at seat " << selectedComp->data.getSeatLoc() << "\n"; 
        return;  
    }
}

void Lab::displayLab()
{
    //Loop through every node in the LinkedListß
}

void Lab::assignLabSize(int labSize_)
{
    labSize = labSize_;
}

void Lab::assignLabName(std::string labName_)
{
    labName = labName_;
}

void Lab::fillWithCompuNodes()
{
    Computer newComputer;

    labOccupancy = 0;
    for(int i = 0; i < labSize; i++)
    {
        compuLab.appendNode(newComputer);
    }
}