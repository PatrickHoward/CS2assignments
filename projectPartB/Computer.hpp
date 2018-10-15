#pragma once 

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