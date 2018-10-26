#ifndef
#define COMPUTER

#include <string>

class Computer
{
  public:
    Computer();
    
    //Pr - Nothing
    //Po - Void function, Performs the login logic
    void login();

    //Pr - Nothing
    //Po - Void function, performs the logout logic
    void logout();
    
    //Pr - Nothing
    //Po - Returns a pseudorandomized integer from 1 to 99999 
    int makeID();

    //Pr - Nothing
    //Po - Returns the assigned ID to that respective computer object
    int getID();

    //Pr - Nothing
    //Po - Returns a string with the assigned studetn name for the respective computer object
    std::string getStudentName();

    void assignID(int userID_);
    void assignStudentName(std::string studentName_);
    void assignTime(int timeUsed_);

  private:
    int userID;
    std::string studentName; //Max 35 chars.
    int timeUsed;

};

#endif