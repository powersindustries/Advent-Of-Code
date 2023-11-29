#include "Day4.h"
#include <string>
#include <fstream>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day4::Part1()
{
    // Read text file.
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day4Data.txt");
    std::ifstream readFile(sDataPath);
    std::string currLine;

    int iOutput = 0;

    while (getline(readFile, currLine))
    {
        std::string sTempString = "";
        bool bLeftPairSet = false;
        SectionData leftPair;
        SectionData rightPair;

        // Read txt file and populate leftPair and rightPair data.
        const int iCurrLineSize = static_cast<int>(currLine.size());
        for (int x = 0; x < iCurrLineSize; ++x)
        {
            const char cCurrChar = currLine[x];
            if (cCurrChar == '-')
            {
                if (bLeftPairSet)
                {
                    rightPair.m_iStart = std::stoi(sTempString);
                    sTempString.clear();
                }
                else
                {
                    leftPair.m_iStart = std::stoi(sTempString);
                    sTempString.clear();
                }
            }
            else if (cCurrChar == ',')
            {
                bLeftPairSet = true;
                leftPair.m_iEnd = std::stoi(sTempString);

                sTempString.clear();
            }
            else
            {
                sTempString += cCurrChar;
            }
        }

        // Set end value for rightPair.
        rightPair.m_iEnd = std::stoi(sTempString);

        // Add left and right pairs to m_SectionDataPairsVector.
        m_SectionDataPairsVector.push_back(SectionDataPairs(leftPair, rightPair));

        // Calculate final output.
        if (PairContainsPair(leftPair, rightPair))
        {
            iOutput++;
        }
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day4::Part2()
{
    int iOutput = 0;

    for (int x = 0; x < m_SectionDataPairsVector.size(); ++x)
    {

        if (PairsOverlap(m_SectionDataPairsVector[x].m_First, m_SectionDataPairsVector[x].m_Second))
        {
            iOutput++;
        }
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
bool Day4::PairContainsPair(SectionData inLeft, SectionData inRight)
{
    bool bLeftContainsRight = inLeft.m_iStart >= inRight.m_iStart && inLeft.m_iEnd <= inRight.m_iEnd;
    bool bRightContainsLeft = inLeft.m_iStart <= inRight.m_iStart && inLeft.m_iEnd >= inRight.m_iEnd;
    return bLeftContainsRight || bRightContainsLeft;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
bool Day4::PairsOverlap(SectionData inLeft, SectionData inRight)
{
    if (PairContainsPair(inLeft, inRight))
    {
        return true;
    }

    bool bLeftOverlapsRight = inLeft.m_iEnd >= inRight.m_iStart;
    bool bRightOverlapsLeft = inLeft.m_iStart <= inRight.m_iEnd;
    return bLeftOverlapsRight && bRightOverlapsLeft;
}