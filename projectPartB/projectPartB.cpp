#include<iostream>
#include<string>//For strings (wow)
#include<limits>

#include "Computer.hpp"
#include "Menu.hpp"

/*
  PROJECT PART B - Patrick M. Howard (pmh41) - LabTrac
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
  Menu instance;

  srand(time(NULL)); //Set the seed for random IDs.
  instance.printHeader(); //Print the header upon startup.
  std::cout << "| Welcome to LabTrac, here are a list of the available\n| computer labs\n\n";

  //Print all available labs
  for(int i = 0; i < NUMLABS-1; ++i)
  {
    std::cout << "| Lab #" << i+1 << " for " << UNIVERSITYNAMES[i] << "\n";
  }
  std::cout << "| Lab #" << NUMLABS << " for " << UNIVERSITYNAMES[NUMLABS - 1] << "\n\n";

  instance.printMenu(); //Print available options.
  
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
