#ifndef COMPUTER
#define COMPUTER

#include <string>
#include "ioHandiling.hpp"

class Computer
{
  public:
    Computer();
    
    //Pr - Takes in a LogFile object so a login can be written to labTrac_log.txt.
    //Po - Void function, Performs the login logic
    void login(int seatLoc_, ioHandiling::LogFile& file);

    //Pr - Nothing
    //Po - Void function, performs the logout logic
    void logout(ioHandiling::LogFile& file);
    
    //Pr - Nothing
    //Po - Returns a pseudorandomized integer from 1 to 99999 
    int makeID();

    //The following three access thier appropriate attributes.
    int getID() const;
    std::string getStudentName() const;
    int getSeatLoc() const;

    //The following three take in their respective objects that they modify within the computer object.
    void assignID(const int userID_);
    void assignStudentName(std::string& studentName_);
    void assignTime(const int timeUsed_);

  private:
    int userID;
    std::string studentName; //Max 35 chars.
    int timeUsed;

    int seatLoc;
};

#endif