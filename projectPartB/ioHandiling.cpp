#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

#include "ioHandiling.hpp"

using namespace std;

int ioHandiling::promptInt(std::string question, int minVal, int maxVal)
{
    int inputVal;
    
    do
    {
        cout << "| " << question << " ( " << minVal << " - " << maxVal << " ) > ";
        cin >> inputVal;

        if(std::cin.fail() || inputVal < minVal || inputVal > maxVal)
        {
            cout << "| Invalid input! Please try again!\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return inputVal;
        }
    } while(true);
}

string ioHandiling::promptString(std::string question, int minLen, int maxLen)
{
    string inputVal;

    do
    {
        std::cout << "| " << question << " ( max " << maxLen << " chars) > ";
        std::getline(std::cin, inputVal);

        if(inputVal.length() <= minLen || inputVal.length() > maxLen)
        {
            std::cout << "| Invalid input, please input less than " << maxLen << ".\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return inputVal;
        }
    } while(true);
}

string ioHandiling::getTime()
{
    time_t now = time(0);
    char* timeIn = ctime(&now);
    timeIn[0] = '\0';
    return (string)timeIn;
}

//Start of logFile class methods
ioHandiling::logFile::logFile(std::string fileName_)
    : fileName(fileName_)
{

}

void ioHandiling::logFile::writeLine(std::string& line)
{
    file.open(fileName, ios::app);
    
    file << line;
    file.close();
}

