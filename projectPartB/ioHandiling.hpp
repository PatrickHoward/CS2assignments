#pragma once

#include <string>

namespace ioHandiling
{
    int promptInt(std::string question, int minVal, int maxVal);

    std::string promptString(std::string question, int minLen, int maxLen);
}