#include "Day3.h"
#include <fstream>

#define GEAR_CHARACTER '*'


// ----------------------------------------------------------------
// ----------------------------------------------------------------
Day3::Day3()
{
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day3Data.txt");
    std::ifstream readFile(sDataPath);
    std::string sCurrLine;

    int iLineIndex = 0;
    while (getline(readFile, sCurrLine))
    {
        m_vSchematic.push_back(sCurrLine);

        const int iLineSize = static_cast<int>(sCurrLine.size());
        for (int x = 0; x < iLineSize; ++x)
        {
            const char cCurrChar = sCurrLine[x];
            if (cCurrChar != '.' && !std::isdigit(cCurrChar))
            {
                m_vSymbolLocations.push_back(SymbolLocationData(iLineIndex, x, cCurrChar == GEAR_CHARACTER));
            }
        }

        iLineIndex++;
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day3::Part1()
{
    int iOutput = 0;

    const int iSymbolLocationSize = static_cast<int>(m_vSymbolLocations.size());
    for (int x = 0; x < iSymbolLocationSize; ++x)
    {
        iOutput += GetNumberByPairPart1(m_vSymbolLocations[x]);
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day3::Part2()
{
    int iOutput = 0;

    const int iSymbolLocationSize = static_cast<int>(m_vSymbolLocations.size());
    for (int x = 0; x < iSymbolLocationSize; ++x)
    {
        iOutput += GetNumberByPairPart2(m_vSymbolLocations[x]);
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day3::GetNumberByPairPart1(const SymbolLocationData &inSymbolLocationData)
{
    int iOutput = 0;

    std::string sCurrLine = m_vSchematic[inSymbolLocationData.m_iLineIndex];
    std::string sTopLine =
            (inSymbolLocationData.m_iLineIndex - 1) >= 0 ? m_vSchematic[inSymbolLocationData.m_iLineIndex - 1] : "";
    std::string sBottomLine = (inSymbolLocationData.m_iLineIndex + 1) < m_vSchematic.size() ? m_vSchematic[
            inSymbolLocationData.m_iLineIndex + 1] : "";

    // Top.
    if (!sTopLine.empty())
    {
        iOutput += CalculateRow(sTopLine, inSymbolLocationData.m_iCharacterIndex);
    }

    // Bottom.
    if (!sBottomLine.empty())
    {
        iOutput += CalculateRow(sBottomLine, inSymbolLocationData.m_iCharacterIndex);
    }

    // Current Line.
    if (!sBottomLine.empty())
    {
        iOutput += CalculateRow(sCurrLine, inSymbolLocationData.m_iCharacterIndex);
    }


    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day3::GetNumberByPairPart2(const SymbolLocationData &inSymbolLocationData)
{
    int iOutput = 0;

    std::string sCurrLine = m_vSchematic[inSymbolLocationData.m_iLineIndex];
    std::string sTopLine =
            (inSymbolLocationData.m_iLineIndex - 1) >= 0 ? m_vSchematic[inSymbolLocationData.m_iLineIndex - 1] : "";
    std::string sBottomLine = (inSymbolLocationData.m_iLineIndex + 1) < m_vSchematic.size() ? m_vSchematic[
            inSymbolLocationData.m_iLineIndex + 1] : "";

    if (inSymbolLocationData.m_bIsGear)
    {
        std::vector<int> vOutput;

        // Top.
        if (!sTopLine.empty())
        {
            std::vector<int> vRowCalculation = CalculateRowForGear(sTopLine, inSymbolLocationData.m_iCharacterIndex);
            const int iRowCalculationSize = static_cast<int>(vRowCalculation.size());
            for (int x = 0; x < iRowCalculationSize; ++x)
            {
                if (vRowCalculation[x] > 0)
                {
                    vOutput.push_back(vRowCalculation[x]);
                }
            }
        }

        // Bottom.
        if (!sBottomLine.empty())
        {
            std::vector<int> vRowCalculation = CalculateRowForGear(sBottomLine, inSymbolLocationData.m_iCharacterIndex);
            const int iRowCalculationSize = static_cast<int>(vRowCalculation.size());
            for (int x = 0; x < iRowCalculationSize; ++x)
            {
                if (vRowCalculation[x] > 0)
                {
                    vOutput.push_back(vRowCalculation[x]);
                }
            }
        }

        // Current Line.
        if (!sBottomLine.empty())
        {
            std::vector<int> vRowCalculation = CalculateRowForGear(sCurrLine, inSymbolLocationData.m_iCharacterIndex);
            const int iRowCalculationSize = static_cast<int>(vRowCalculation.size());
            for (int x = 0; x < iRowCalculationSize; ++x)
            {
                if (vRowCalculation[x] > 0)
                {
                    vOutput.push_back(vRowCalculation[x]);
                }
            }
        }

        const int iOutputSize = static_cast<int>(vOutput.size());
        if (iOutputSize < 2)
        {
            return 0;
        }

        int iTempOutput = 1;
        for (int x = 0; x < iOutputSize; ++x)
        {
            iTempOutput *= vOutput[x];
        }

        iOutput += iTempOutput;
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day3::CalculateRow(const std::string inRow, const int inIndex)
{
    int iOutput = 0;

    // Check if places around index have numbers in them.
    std::string sSubstr = "";
    int iStartIndex = inIndex - 1;
    if (iStartIndex < 0)
    {
        sSubstr = inRow.substr(inIndex, 2);
    }
    else
    {
        sSubstr = inRow.substr(iStartIndex, 3);
    }

    if (std::any_of(sSubstr.begin(), sSubstr.end(), ::isdigit))
    {
        const int iLeftIndex = inIndex - 1;
        const int iRightIndex = inIndex + 1;

        // Check current index. If it includes a number, search for numbers above.
        if (std::isdigit(inRow[inIndex]))
        {
            // Left side.
            std::string sLeft = "";
            if (iLeftIndex >= 0)
            {
                for (int x = iLeftIndex; x >= 0; --x)
                {
                    if (std::isdigit(inRow[x]))
                    {
                        sLeft += inRow[x];
                    }
                    else
                    {
                        break;
                    }
                }

                std::reverse(sLeft.begin(), sLeft.end());
            }

            std::string sRight = "";
            for (int x = iRightIndex; x < inRow.size(); ++x)
            {
                if (std::isdigit(inRow[x]))
                {
                    sRight += inRow[x];
                }
                else
                {
                    break;
                }
            }

            std::string sFullNumber = sLeft + inRow[inIndex] + sRight;

            iOutput += std::stoi(sFullNumber);
        }
        else
        {
            // Left. Reverse Search
            if (iStartIndex >= 0 && std::isdigit(inRow[iStartIndex]))
            {
                std::string sNumber = "";
                for (int x = iStartIndex; x >= 0; --x)
                {
                    if (std::isdigit(inRow[x]))
                    {
                        sNumber += inRow[x];
                    }
                    else
                    {
                        break;
                    }
                }

                std::reverse(sNumber.begin(), sNumber.end());
                iOutput += std::stoi(sNumber);
            }

            // Right.
            const int iEndIndex = iStartIndex + 2;
            if (iEndIndex < inRow.size() && std::isdigit(inRow[iEndIndex]))
            {
                std::string sNumber = "";
                for (int x = iEndIndex; x < inRow.size(); ++x)
                {
                    if (std::isdigit(inRow[x]))
                    {
                        sNumber += inRow[x];
                    }
                    else
                    {
                        break;
                    }
                }

                iOutput += std::stoi(sNumber);
            }
        }
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
std::vector<int> Day3::CalculateRowForGear(const std::string inRow, const int inIndex)
{
    std::vector<int> vOutput;

    // Check if places around index have numbers in them.
    std::string sSubstr = "";
    int iStartIndex = inIndex - 1;
    if (iStartIndex < 0)
    {
        sSubstr = inRow.substr(inIndex, 2);
    }
    else
    {
        sSubstr = inRow.substr(iStartIndex, 3);
    }

    if (std::any_of(sSubstr.begin(), sSubstr.end(), ::isdigit))
    {
        const int iLeftIndex = inIndex - 1;
        const int iRightIndex = inIndex + 1;

        // Check current index. If it includes a number, search for numbers above.
        if (std::isdigit(inRow[inIndex]))
        {
            // Left side.
            std::string sLeft = "";
            if (iLeftIndex >= 0)
            {
                for (int x = iLeftIndex; x >= 0; --x)
                {
                    if (std::isdigit(inRow[x]))
                    {
                        sLeft += inRow[x];
                    }
                    else
                    {
                        break;
                    }
                }

                std::reverse(sLeft.begin(), sLeft.end());
            }

            std::string sRight = "";
            for (int x = iRightIndex; x < inRow.size(); ++x)
            {
                if (std::isdigit(inRow[x]))
                {
                    sRight += inRow[x];
                }
                else
                {
                    break;
                }
            }

            std::string sFullNumber = sLeft + inRow[inIndex] + sRight;
            vOutput.push_back(std::stoi(sFullNumber));
        }
        else
        {
            // Left. Reverse Search
            if (iStartIndex >= 0 && std::isdigit(inRow[iStartIndex]))
            {
                std::string sNumber = "";
                for (int x = iStartIndex; x >= 0; --x)
                {
                    if (std::isdigit(inRow[x]))
                    {
                        sNumber += inRow[x];
                    }
                    else
                    {
                        break;
                    }
                }

                std::reverse(sNumber.begin(), sNumber.end());
                vOutput.push_back(std::stoi(sNumber));
            }

            // Right.
            const int iEndIndex = iStartIndex + 2;
            if (iEndIndex < inRow.size() && std::isdigit(inRow[iEndIndex]))
            {
                std::string sNumber = "";
                for (int x = iEndIndex; x < inRow.size(); ++x)
                {
                    if (std::isdigit(inRow[x]))
                    {
                        sNumber += inRow[x];
                    }
                    else
                    {
                        break;
                    }
                }

                vOutput.push_back(std::stoi(sNumber));
            }
        }
    }

    return vOutput;
}