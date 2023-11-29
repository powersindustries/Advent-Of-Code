#include "Day3.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

#define ASCII_OFFSET_UPPERCASE 38
#define ASCII_OFFSET_LOWERCASE 96


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day3::Part1()
{
    // Read text file.
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day3Data.txt");
    std::ifstream readFile(sDataPath);
    std::string currLine;

    std::vector<char> vCommonItemsVector;
    while (getline(readFile, currLine))
    {
        const int iLineSize = static_cast<int>(currLine.size());
        std::string sFirstCompartment = currLine.substr(0, iLineSize / 2);
        std::string sSecondCompartment = currLine.substr(iLineSize / 2, iLineSize);

        // Sort comparison strings. Makes searching more efficient.
        std::sort(sFirstCompartment.begin(), sFirstCompartment.end());
        std::sort(sSecondCompartment.begin(), sSecondCompartment.end());

        vCommonItemsVector.push_back(GetCommonCharTwo(sFirstCompartment, sSecondCompartment));
    }

    return CalculateCommonItemsAmount(vCommonItemsVector);
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day3::Part2()
{
    // Read text file.
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day3Data.txt");
    std::ifstream readFile(sDataPath);
    std::string currLine;

    std::vector<char> vCommonItemsVector;
    std::vector<std::string> vTempStringVector;
    while (getline(readFile, currLine))
    {
        std::sort(currLine.begin(), currLine.end());

        vTempStringVector.push_back(currLine);

        if (vTempStringVector.size() == 3)
        {
            vCommonItemsVector.push_back(
                    GetCommonCharThree(vTempStringVector[0], vTempStringVector[1], vTempStringVector[2]));

            vTempStringVector.clear();
        }
    }

    return CalculateCommonItemsAmount(vCommonItemsVector);
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
char Day3::GetCommonCharTwo(const std::string &first, const std::string &second)
{
    for (int x = 0; x < first.size(); ++x)
    {
        for (int y = 0; y < second.size(); ++y)
        {
            if (first[x] == second[y])
            {
                return first[x];
            }
        }
    }

    return char();
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
char Day3::GetCommonCharThree(const std::string &first, const std::string &second, const std::string &third)
{
    for (int x = 0; x < first.size(); ++x)
    {
        for (int y = 0; y < second.size(); ++y)
        {
            for (int z = 0; z < third.size(); ++z)
            {
                if (first[x] == second[y] && second[y] == third[z])
                {
                    return first[x];
                }
            }
        }
    }

    return char();
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day3::CalculateCommonItemsAmount(const std::vector<char> &InCommonItemsVector)
{
    int iOutput = 0;

    const int iCommonItemsVectorSize = static_cast<int>(InCommonItemsVector.size());
    for (int x = 0; x < iCommonItemsVectorSize; ++x)
    {
        const char cCurrLetter = InCommonItemsVector[x];
        if (std::isupper(cCurrLetter))
        {
            iOutput += (int(cCurrLetter) - ASCII_OFFSET_UPPERCASE);
        }
        else
        {
            iOutput += (int(cCurrLetter) - ASCII_OFFSET_LOWERCASE);
        }
    }

    return iOutput;
}