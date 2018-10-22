#pragma once

#include <string>

struct Menu
{
    void printHeader();
 
    void printLabs(const std::string labs[]), int numLabs);
 
    void printMenu();
};