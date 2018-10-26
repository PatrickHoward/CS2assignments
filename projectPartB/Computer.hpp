#ifndef COMPUTER
#define COMPUTER

#include <string>
#include "ioHandiling.hpp"

class Computer
{
  public:
    Computer();
    
    //Pr - Nothing
    //Po - Void function, Performs the login logic
    void login(ioHandiling::logFile file);

    //Pr - Nothing
    //Po - Void function, performs the logout logic
    void logout();
    
    //Pr - Nothing
    //Po - Returns a pseudorandomized integer from 1 to 99999 
    int makeID();

    //Pr - Nothing
    //Po - Returns the assigned ID to that respective computer object
    int getID() const;

    //Pr - Nothing
    //Po - Returns a string with the assigned studetn name for the respective computer object
    std::string getStudentName() const;

    //The following three take in their respective objects that they modify within the computer object.
    void assignID(const int userID_);
    void assignStudentName(std::string& studentName_);
    void assignTime(const int timeUsed_);

  private:
    int userID;
    std::string studentName; //Max 35 chars.
    int timeUsed;

};

#endif