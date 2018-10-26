#ifndef IOHANDILING
#define IOHANDILING

#include <string>
#include <iostream>
#include <fstream>

namespace ioHandiling
{
    //Pr - Takes a string, a minimum accepted value, and a maximum accepted value
    //Po - Returns an integer within the accepted range.
    int promptInt(std::string question, int minVal, int maxVal);

    //Pr - Takes a string, a minimum accepted value, and a maximum accepted value
    //Po - Returns a string with a length within the accepted range.
    std::string promptString(std::string question, int minLen, int maxLen);

    //Pr - Absolutely nothing, these pre and post conditions are getting old...
    //Po - Returns a string of the time, like the prototype says.
    std::string getTime();

    class logFile
    {
    public:
        logFile(std::string fileName_);

        //Pr - Takes a string in
        //Po - Void function, puts it into a file specified at the beginning.
        void writeLine(std::string& line);
        
    private:
        std::string fileName;
        std::fstream file;
    };
}

#endif