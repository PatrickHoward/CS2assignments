#pragma once

#include <iostream>
#include <string>

#include "ioHandiling.hpp"

using namespace std;

int ioHandiling::promptInt(std::string question, int minVal, int maxVal)
{
    int inputVal;
    cout << "| " << question << " ( " << minVal << " - " << maxVal << " ) > ";

    
    do
    {
        cin >> inputVal;

        if(std::cin.fail || inputVal < minVal || inputVal > maxVal)
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

