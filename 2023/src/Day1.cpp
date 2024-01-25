#include "Day1.h"
#include <string>
#include <fstream>
#include <algorithm>

#define DEFAULT_SUBSTRING_VAL -1

// ----------------------------------------------------------------
// ----------------------------------------------------------------
Day1::Day1()
{
    m_vNumberWordVector.push_back("one");
    m_vNumberWordVector.push_back("two");
    m_vNumberWordVector.push_back("three");
    m_vNumberWordVector.push_back("four");
    m_vNumberWordVector.push_back("five");
    m_vNumberWordVector.push_back("six");
    m_vNumberWordVector.push_back("seven");
    m_vNumberWordVector.push_back("eight");
    m_vNumberWordVector.push_back("nine");
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day1::Part1()
{
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day1Data.txt");
    std::ifstream readFile(sDataPath);
    std::string sCurrLine;

    int iOutput = 0;
    while (getline(readFile, sCurrLine))
    {
        // Get all number from sCurrLine.
        std::vector<char> vNumberList;
        for (int x = 0; x < sCurrLine.length(); ++x)
        {
            if (std::isdigit(sCurrLine[x]))
            {
                vNumberList.push_back(sCurrLine[x]);
            }
        }

        // Add to iOutput.
        if (vNumberList.empty())
        {
            continue;
        }
        else if (vNumberList.size() > 1)
        {
            std::string sOutputString;
            sOutputString.push_back(vNumberList[0]);
            sOutputString.push_back(vNumberList[vNumberList.size() - 1]);
            iOutput += std::stoi(sOutputString);
        }
        else
        {
            std::string sOutputString;
            sOutputString.push_back(vNumberList[0]);
            sOutputString.push_back(vNumberList[0]);
            iOutput += std::stoi(sOutputString);
        }
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day1::Part2()
{
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day1Data.txt");
    std::ifstream readFile(sDataPath);
    std::string sCurrLine;

    int output = 0;
    while (getline(readFile, sCurrLine))
    {
        std::string sTempCurrLine = sCurrLine;

        // Replace number strings with number character.
        bool bComplete = false;
        while (!bComplete)
        {
            int iTempIndex = 0;
            for (int x = 0; x < sTempCurrLine.size(); x++)
            {
                std::string sTempWord = sTempCurrLine.substr(0, x + 1);
                if (ReplaceWord(sTempCurrLine, sTempWord))
                {
                    break;
                }

                iTempIndex++;
            }

            if (iTempIndex == sTempCurrLine.size())
            {
                bComplete = true;
            }
        }

        // Get all number from sCurrLine.
        std::vector<char> sNumberList;
        for (int x = 0; x < sTempCurrLine.length(); ++x)
        {
            if (std::isdigit(sTempCurrLine[x]))
            {
                sNumberList.push_back(sTempCurrLine[x]);
            }
        }

        // Add to output.
        if (sNumberList.empty())
        {
            continue;
        }
        else if (sNumberList.size() > 1)
        {
            std::string sOutputString;
            sOutputString.push_back(sNumberList[0]);
            sOutputString.push_back(sNumberList[sNumberList.size() - 1]);
            output += std::stoi(sOutputString);
        }
        else
        {
            std::string sOutputString;
            sOutputString.push_back(sNumberList[0]);
            sOutputString.push_back(sNumberList[0]);
            output += std::stoi(sOutputString);
        }
    }

    return output;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
bool Day1::ReplaceWord(std::string &inFullString, const std::string& inSubstring)
{
    for (int y = 0; y < m_vNumberWordVector.size(); ++y)
    {
        const std::string &sCurrNumberWord = m_vNumberWordVector[y];

        const int iWordFoundIndex = inSubstring.find(sCurrNumberWord);
        if (iWordFoundIndex != std::string::npos)
        {
            std::string sValue = std::to_string(y + 1);
            inFullString.replace(iWordFoundIndex, sCurrNumberWord.size() - 1, sValue);

            return true;
        }
    }

    return false;
}
