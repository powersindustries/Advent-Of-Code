#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Day1.h"


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Day1::Part1(std::vector<int>& inVector)
{
    // Read text file.
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/2022/Data/Day1Data.txt");
    std::ifstream readFile(sDataPath);
    std::string currLine;

    int iTempValue = 0;
    while (getline(readFile, currLine))
    {
        if(currLine.empty())
        {
            inVector.push_back(iTempValue);

            iTempValue = 0;
        }
        else
        {
            iTempValue += std::stoi(currLine);
        }
    }

    // Add last value missed by while() statement.
    inVector.push_back(iTempValue);

    // Sort array with highest value first.
    std::sort(inVector.begin(), inVector.end(), std::greater<int>());
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day1::Part2(const std::vector<int> &inVector)
{
    const int iElfCount = 3;

    int iOutput = 0;
    for(int x=0; x < iElfCount; ++x)
    {
        iOutput += inVector[x];
    }

    return iOutput;
}