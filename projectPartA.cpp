#include<iostream>
#include<ctime>//For making the seed (for rand())
#include<cstdlib>//For rand()  
#include<iomanip>//For manipulating the input! Yay!
#include<string>//For strings (wow)
#include<limits>
/*
  PROJECT PART A - Patrick M. Howard (pmh41) - LabTrac
  Copyright 2018, all rights reserved. 
  pmh41@zips.uakron.edu
  ver 0.34 9.28.2018
  Purpose: This program manages computer labs for several different universities. It can sign on, sign off users and keep track of 
           where they are in the system. 
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
    
    //mkID randomly generates a new ID number from 1-99999 and returns it.
    int mkID();
    
    //I created some accessor and mutator functions, just in case I needed them...
    int getID();
    std::string getStudentName();
    
    //Mutator functions.
    void assignID(int);
    void assignStudentName(std::string);
    void assignTime(int);

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

//Clears the entire line of an input during input verification. 
void scrub(std::istream& is)
{
  is.clear();
  is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
  srand(time(NULL)); //Set the seed for random IDs.
  printHeader(); //Print the header upon startup.
  std::cout << "| Welcome to LabTrac, here are a list of the available\n| computer labs\n\n";

  //Print all available labs
  for(int i = 0; i < NUMLABS-1; ++i)
  {
    std::cout << "| Lab #" << i+1 << " for " << UNIVERSITYNAMES[i] << "\n";
  }
  std::cout << "| Lab #" << NUMLABS << " for " << UNIVERSITYNAMES[NUMLABS - 1] << "\n\n";

  printMenu(); //Print available options.
  
  //Now, lets go ahead and write the array for the labs.
  Computer* labArray[NUMLABS]; 
  
  //Loop through and set up the dynamic arrays. 
  for(int i = 0; i < NUMLABS; ++i)
  {
    labArray[i] = new Computer[LABSIZES[i]];
  }
  
  //Goes through the main menu.
  bool active = true;
  while(active)
  {
    int choice; 
    std::cout << "| > "; 
    std::cin >> choice;

    if(std::cin.fail() || choice == 0 || choice > 5)
    {
      //Invalid input, clear and clean the buffer.
      scrub(std::cin);
    }

    //I cant seem to get the labArray to "pass" to another function, so for now I put everything in the switch statement. 
    switch(choice)
    {
      case 1: //Simulate a login 
      { int labSelection;
        int computerAssignment;

        //Get the lab
        bool invalidSelection = true;
        while(invalidSelection)
        {
          std::cout << "| For which lab? (1 - " << NUMLABS << ") > ";
	  std::cin >> labSelection;

          if(std::cin.fail() || labSelection <= 0 || labSelection > NUMLABS)
          {
            std::cout << "| Invalid input, please try again.\n";
            //Invalid input, cleaning buffer.
          }
          else
          {
            invalidSelection = false;
          }
          scrub(std::cin);
        }

        std::cout << "| Selected " << UNIVERSITYNAMES[labSelection-1] << "!\n";
        
        //Get the computer assignment.
        invalidSelection = true;
        while(invalidSelection)
        {
          std::cout << "| Select the seat assignment (1 - " << LABSIZES[labSelection-1] << ") > ";
	  std::cin >> computerAssignment;

          if(std::cin.fail() || computerAssignment <= 0 || computerAssignment > LABSIZES[labSelection-1])
          {
            std::cout << "| Invalid input, please try again.\n";
            //Invalid input, cleaning buffer.
          }
          else
          {
            invalidSelection = false;
          }
          scrub(std::cin);
        }
        labArray[labSelection-1][computerAssignment-1].login();//Call the login method for the selected object.
      }
      break;
      case 2:
        {
          bool invalidInput = true;
          int userID;
          while(invalidInput)
          {
            std::cout << "| Input the User ID to logout > ";
            std::cin >> userID;
          
            if(std::cin.fail() || userID < 1 || userID > 99999)
            {
              std::cout << "| Invalid input, please try again.\n";
              scrub(std::cin);
            }
            else
            {
              invalidInput = false;
            }
          }
          
          for(int i = 0; i < NUMLABS; ++i)
          {
            for(int j = 0; j < LABSIZES[i]; ++j)
            {
              if(labArray[i][j].getID() == userID)
              {
                labArray[i][j].logout();
              }
            }
          }
        }
        break;
      case 3://Search each lab.
        {
          bool invalidInput = true;
          int userID;
          while(invalidInput)
          {
            std::cout << "| Input the User ID to logout > ";
            std::cin >> userID;

            if(std::cin.fail() || userID < 1 || userID > 99999)
            {
              std::cout << "| Invalid input, please try again.\n";
              scrub(std::cin);
            }
            else
            {
              invalidInput = false;
            }
          }

          for(int i = 0; i < NUMLABS; ++i)
          {
            for(int j = 0; j < LABSIZES[i]; ++j)
            {
              if(labArray[i][j].getID() == userID)
              {
                std::cout << "| Found " << labArray[i][j].getStudentName() << " in lab " << i+1 << " at computer " << j+1 << ". \n";
              }
            }
          }
        }
        break;
      case 4: //Display a lab.
        {
          int labSelection;
          bool invalidInput = true;
            scrub(std::cin);
          while(invalidInput)
          {
            std::cout << "| Which lab do you want to display? (1 - " << NUMLABS << ") > ";
            std::cin >> labSelection;
          
            if(std::cin.fail() || labSelection > NUMLABS || labSelection <= 0)
            {
              std::cout << "| Invalid input, please try again!\n";
              //Invalid input, scrubbing...
            }
            else
            {
              invalidInput = false;
            }
            scrub(std::cin);
          }
          
          std::cout << "| Selected " << UNIVERSITYNAMES[labSelection-1] << "\n";
          for(int i = 0; i <= LABSIZES[labSelection-1]; ++i)
          { //Theres a segmentation issue, and I cant figure it out for the life of me... Still working on it. 
            std::cout << i+1 << ": " 
                      << (labArray[labSelection-1][i].getID() != -1 ? std::to_string(labArray[labSelection-1][i].getID()) :"empty") 
                      << " " << (i % 5 == 0 ? "\n" : NULL);
          }
        }
        break;
      case 5:
      {
        std::cout << "| Exiting program, goodbye!\n";
        active = false;
      }
      break;
      default: 
      {
        std::cout << "| Invalid input, please try again.\n";
        scrub(std::cin);
      }
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
  std::cout << "| Assigned user to: " << std::setfill('0') << std::setw(5) << userID << "\n" << std::setfill(' ');


  //Now to assign the name...  
  bool invalidInput = true; //Unlike the American judicial system, invalid until proven valid.
  while(invalidInput)//Check to make sure the name is less than 35 characters 
  {

    std::cout << "| Please input a name (max 35 chars) > ";
    std::getline(std::cin, studentName);

    if(studentName.length() > 35 || studentName.length() == 0)
    { 
      //Input is deemed invalid, clean the buffer and try again.
      std::cout << "| Invalid input, please try again.\n";
      scrub(std::cin);
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
    
    if(std::cin.fail() || timeUsed > 60 || timeUsed % 15 != 0)
    {
      //Invalid is deemed invalid, clean the buffer and try agian. 
      std::cout << "| Invalid input, please try again.\n";
     
      scrub(std::cin);
    }
    else
    {
      //Valid input, set invalidInput to false and move on.
      invalidInput = false;
    } 
    std::cout << "| Assigned " << studentName << " to user# " << userID << ".\n";
  } 
}

void Computer::logout()
{
  std::cout << "| " << studentName << " has been signed out. \n";

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

void Computer::assignID(int id)
{userID = id;}

void Computer::assignStudentName(std::string name)
{studentName = name;}

void Computer::assignTime(int time)
{timeUsed = time;  }  

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
    std::cout << "| " << i+1 << ") " << menuOptions[i] << "\n";
  }
  
}
