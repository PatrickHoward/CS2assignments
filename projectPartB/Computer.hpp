#pragma once 

class Computer
{
  public:
    Computer();
    
    void login();
    void logout();
    
    int makeID();
    int getID();
    std::string getStudentName();

    void assignID(int);
    void assignStudentName(std::string);
    void assignTime(int);

  private:
    int userID;
    std::string studentName; //Max 35 chars.
    int timeUsed;

};