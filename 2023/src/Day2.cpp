#include "Day2.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define RED "red"
#define GREEN "green"
#define BLUE "blue"

#define RED_MAX 12
#define GREEN_MAX 13
#define BLUE_MAX 14


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day2::Part1()
{
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day2Data.txt");
    std::ifstream readFile(sDataPath);
    std::string sCurrLine;

    int iOutput = 0;

    int iGameIndex = 0;
    while (getline(readFile, sCurrLine))
    {
        iGameIndex++;

        std::string sTempCurrLine = sCurrLine;

        const int iIndex = sTempCurrLine.find(':');
        sTempCurrLine.erase(0, iIndex + 2);

        std::stringstream tempStringStream(sTempCurrLine);
        std::string sSegment;

        bool bExceedsLimit = false;

        while (std::getline(tempStringStream, sSegment, ';'))
        {
            std::stringstream gameStringStream(sSegment);
            std::string sgameSegment;

            while (std::getline(gameStringStream, sgameSegment, ','))
            {
                if (sgameSegment[0] == ' ')
                {
                    sgameSegment.erase(0, 1);
                }

                const int iSpaceIndex = sgameSegment.find(' ');
                const std::string sAmount = sgameSegment.substr(0, iSpaceIndex);
                int iAmount = std::stoi(sAmount);

                if (sgameSegment.find(GREEN) != std::string::npos)
                {
                    if (iAmount > GREEN_MAX)
                    {
                        bExceedsLimit = true;
                    }
                }
                else if (sgameSegment.find(RED) != std::string::npos)
                {
                    if (iAmount > RED_MAX)
                    {
                        bExceedsLimit = true;
                    }
                }
                else if (sgameSegment.find(BLUE) != std::string::npos)
                {
                    if (iAmount > BLUE_MAX)
                    {
                        bExceedsLimit = true;
                    }
                }
            }
        }

        if (!bExceedsLimit){
            iOutput += iGameIndex;
        }
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day2::Part2()
{
    // Read text file.
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day2Data.txt");
    std::ifstream readFile(sDataPath);
    std::string sCurrLine;

    int iOutput = 0;

    while (getline(readFile, sCurrLine))
    {
        std::string sTempCurrLine = sCurrLine;

        // Remove game disclaimer.
        const int iIndex = sTempCurrLine.find(':');
        sTempCurrLine.erase(0, iIndex + 2);

        // Separate string by colon character.
        std::stringstream tempStringStream(sTempCurrLine);
        std::string sSegment;

        int iGreenMax = 0;
        int iRedMax = 0;
        int iBlueMax = 0;

        while (std::getline(tempStringStream, sSegment, ';'))
        {
            std::stringstream gameStringStream(sSegment);
            std::string sgameSegment;

            while (std::getline(gameStringStream, sgameSegment, ','))
            {
                if (sgameSegment[0] == ' ')
                {
                    sgameSegment.erase(0, 1);
                }

                const int iSpaceIndex = sgameSegment.find(' ');
                const std::string sAmount = sgameSegment.substr(0, iSpaceIndex);

                int iAmount = std::stoi(sAmount);

                if (sgameSegment.find(GREEN) != std::string::npos)
                {
                    iGreenMax = iAmount > iGreenMax ? iAmount : iGreenMax;
                }
                else if (sgameSegment.find(RED) != std::string::npos)
                {
                    iRedMax = iAmount > iRedMax ? iAmount : iRedMax;
                }
                else if (sgameSegment.find(BLUE) != std::string::npos)
                {
                    iBlueMax = iAmount > iBlueMax ? iAmount : iBlueMax;
                }
            }
        }

        iOutput += (iGreenMax * iRedMax * iBlueMax);
    }

    return iOutput;
}