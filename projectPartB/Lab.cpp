#include <iostream>
#include <string>

#include "Lab.hpp"
#include "ioHandiling.hpp"

Lab::Lab()
{
	labName = "uniname";
	labSize = 0;
}

Lab::Lab(int labSize_, std::string labName_)
    : labSize(labSize_),
    labName(labName_)
{
    fillWithCompuNodes();
}

Computer* Lab::simulateLogin(ioHandiling::LogFile& log)
{

    if(isFull())
    {
        return nullptr;
    }

    ++labOccupancy;

    int seatSelection = ioHandiling::promptInt("Please select a seat assignment.", 1, labSize);

    CompuNode* selectedComp;

    selectedComp = compuLab.goToNComp(seatSelection);
    
    Computer* returningComputer;
    returningComputer = selectedComp->data.login(log);
    
    return returningComputer;
}

bool Lab::simulateLogoff(int userID, ioHandiling::LogFile& log)
{
    CompuNode* selectedComp;
    selectedComp = compuLab.findComputerByID(userID);
    if(selectedComp->data.getID() != -1)
    {
        selectedComp->data.logout(log);
        --labOccupancy;
        
        return true;
    }
    
    return false;
}

Computer* Lab::assignToFirstAvailable(std::string line, ioHandiling::LogFile& log)
{
    if(isFull())
    {
        return nullptr;
    }

    ++labOccupancy;

    int userId = stoi(line.substr(27, 5));
    int timeUsed = stoi(line.substr(35, 2));

    std::string studentName = line.substr(40, line.length() - 40);

    CompuNode* selectedComp;
    selectedComp = compuLab.findComputerByID(-1);

    selectedComp->data.login(userId, studentName, timeUsed, log);
}

void Lab::searchLab(int userID, int labLoc)
{
    CompuNode* selectedComp;

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
    compuLab.displayEach(compuLab.head, 1);
    std::cout << "\n";
}

void Lab::assignLabSize(int labSize_)
{
    labSize = labSize_;
}

void Lab::assignLabName(std::string labName_)
{
    labName = labName_;
}

void Lab::fillWithCompuNodes(int labLoc)
{
    Computer newComputer(labLoc);

    labOccupancy = 0;
    for(int i = 0; i < labSize; i++)
    {
        compuLab.appendNode(newComputer);
    }
}

bool Lab::isFull()
{
    if (labOccupancy >= labSize)
    {
        std::cout << "| !! - Lab occupancy is full at this time, please try again later. - !!\n";
        return true;
    }

    return false;
}

