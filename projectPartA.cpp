#include<iostream>
#include<ctime>//For making the seed (for rand())
#include<cstdlib>//For rand()  
#include<iomanip>//For manipulating the input! Yay!
#include<string>//For strings (wow)
#include<memory>
/*
  PROJECT PART A - Patrick M. Howard (pmh41) - LabTrac
  Copyright 2018, all rights reserved. 
  pmh41@zips.uakron.edu
  ver 0.34 9.28.2018
  Purpose: 
*/

//Global Constants
//Number of computer Labs
const int NUMLABS = 8;
//Number of computers in each lab;
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};

//Universities currently under constract.
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University", "Arizona State University", "North Texas State University", "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};

class Computer
{
  public:
    //Constructors
    Computer(); //Default constructor
    
    //The login and logout functions reassign all three attributes in the object.  
    void login();
    void logout();
    
    int mkID();
    
    int getID();
    std::string getStudentName();
    
  private:
    int userID; //Randomly generates 5 digit ID numbers upon login.
    std::string studentName; //Maximum 35 characters
    int timeUsed; //Should only be in increments of 15 minutes with an hour max.

};

//Prints the header of the program, does not take in any object.
void printHeader();

//Prints the menu of the program, does not take in any object.
void printMenu();

//Searches the provided multidimensional array for the user ID number.
Computer search(int);

int main()
{
  srand(time(NULL)); //Set the seed for random IDs.
  printHeader(); //Print the header upon startup.
  std::cout << "| Welcome to LabTrac, here are a list of the available\n| computer labs\n\n";

  //Print all available labs
  for(int i = 0; i < NUMLABS-1; ++i)
  {
    std::cout << "| Lab #" << i << " for " << UNIVERSITYNAMES[i] << "\n";
  }
  std::cout << "| Lab #" << NUMLABS << " for " << UNIVERSITYNAMES[NUMLABS - 1] << "\n\n";

  printMenu(); //Print available options.
  
  //Now, lets go ahead and write the array for the labs.
  static Computer* labArray[NUMLABS]; 
  
  //Loop through and set up the dynamic arrays. 
  for(int i = 0; i < NUMLABS; ++i)
  {
    labArray[i] = new Computer[LABSIZES[i]];
  }
  
  bool active = true;
  while(active)
  {
    int choice; 
    std::cout << "| > " 
    std::cin >> choice;

    if(std::cin.fail() || choice == 0 || choice > 5)
    {
      //Invalid input, clear and clean the buffer.
      std::cin.clear();
      std::cin.ignore(numeric_limits<std::streamsize)::max(), '\n'
    }
    
    switch choice
    {
      case 1: 
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        std::cout << "| Exiting program, goodbye!\n";
        active = false;
        
    }
  }
}

Computer::Computer()
{
  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

void Computer::login()
{
  //Call mkID and assign userID.
  userID = mkID();

  //Now to assign the name...  
  bool invalidInput = true; //Unlike the American judicial system, invalid until proven valid.
  while(invalidInput)//Check to make sure the name is less than 35 characters 
  {
    std::cout << "| Please input a name (max 35 chars) > ";
    std::cin >> studentName;
    
    if(std::cin.fail() || studentName.length() > 35 || studentName.length() == 0)
    { 
      //Input is deemed invalid, clean the buffer and try again.
      std::cout << "| Invalid input, please try again.\n";
      
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
      //Valid input, set invalidInput to true and move on.
      invalidInput = false;
    }  
  }
  
  //And time... Now this can only be set in 15 minute increments...
  invalidInput = true; //I'm recycling this...
  while(invalidInput)
  {
    std::cout << "| Please input time used (15/30/45/60) > ";
    std::cin >> timeUsed;
    
    if(std::cin.fail() || timeUsed > 60 || timeUsed % 15 == 0)
    {
      //Invalid is deemed invalid, clean the buffer and try agian. 
      std::cout << "| Invalid input, please try again.\n";
     
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
      //Valid input, set invalidInput to true and move on.
      invalidInput = false;
    } 
  } 
}

void Computer::logout()
{
  std::cout << "| " << studentName << " has been signed out.";

  //Reassign initial values.
  userID = -1;
  studentName = "empty";
  timeUsed = 0;
}

int Computer::mkID()
{return rand()%99999;}

int Computer::getID()
{return userID;}

std::string Computer::getStudentName()
{return studentName;}

void printHeader()
{
  std::cout << std::setw(60) << " ___________________________________________________________\n"
            << "|----------------------------------------------------------|\n"
            << "|                         LabTrac                          |\n"
            << "|            Student Computer Lab Tracking System          |\n"
            << "|__________________________________________________________|\n"
            << "|\n";
}

void printMenu()
{
  std::string menuOptions[5] = {"Simulate Login", "Simulate Logoff", "Search", "Display Lab", "Quit"};
  
  std::cout << "| MAIN MENU\n";
  for(int i = 0; i < 5; ++i)
  {
    std::cout << "| " << i << ") " << menuOptions[i] << "\n";
  }

  
}
