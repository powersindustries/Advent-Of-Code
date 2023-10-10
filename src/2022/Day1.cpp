#include "Day1.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day1::Part1()
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
            m_vCalorieVector.push_back(iTempValue);

            iTempValue = 0;
        }
        else
        {
            iTempValue += std::stoi(currLine);
        }
    }

    // Add last value missed by while() statement.
    m_vCalorieVector.push_back(iTempValue);

    // Sort array with highest value first.
    std::sort(m_vCalorieVector.begin(), m_vCalorieVector.end(), std::greater<int>());

    // return highest calorie count.
    return m_vCalorieVector[0];
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day1::Part2()
{
    const int iElfCount = 3;

    int iOutput = 0;
    for(int x=0; x < iElfCount; ++x)
    {
        iOutput += m_vCalorieVector[x];
    }

    return iOutput;
}