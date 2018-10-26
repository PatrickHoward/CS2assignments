#ifndef 
#define IOHANDILING

#include <string>
#include <iostream>
#include <fstream>

namespace ioHandiling
{
    int promptInt(std::string question, int minVal, int maxVal);

    std::string promptString(std::string question, int minLen, int maxLen);

    class logFile
    {
    public:
        logFile(std::string fileName_);

        void writeLine(std::string& line);
        
    private:
        std::string fileName;
        std::fstream file;
    };
}

#endif