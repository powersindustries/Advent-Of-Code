#include "Day5.h"
#include <fstream>


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Day5::InitializeData()
{
//    [G]                 [D] [R]
//    [W]         [V]     [C] [T] [M]
//    [L]         [P] [Z] [Q] [F] [V]
//    [J]         [S] [D] [J] [M] [T] [V]
//    [B]     [M] [H] [L] [Z] [J] [B] [S]
//    [R] [C] [T] [C] [T] [R] [D] [R] [D]
//    [T] [W] [Z] [T] [P] [B] [B] [H] [P]
//    [D] [S] [R] [D] [G] [F] [S] [L] [Q]
//    1   2   3   4   5   6   7   8   9

    m_CrateData.clear();

    // 1.
    std::stack<char> oneStack;
    oneStack.push('D');
    oneStack.push('T');
    oneStack.push('R');
    oneStack.push('B');
    oneStack.push('J');
    oneStack.push('L');
    oneStack.push('W');
    oneStack.push('G');

    // 2.
    std::stack<char> twoStack;
    twoStack.push('S');
    twoStack.push('W');
    twoStack.push('C');

    // 3.
    std::stack<char> threeStack;
    threeStack.push('R');
    threeStack.push('Z');
    threeStack.push('T');
    threeStack.push('M');

    // 4.
    std::stack<char> fourStack;
    fourStack.push('D');
    fourStack.push('T');
    fourStack.push('C');
    fourStack.push('H');
    fourStack.push('S');
    fourStack.push('P');
    fourStack.push('V');

    // 5.
    std::stack<char> fiveStack;
    fiveStack.push('G');
    fiveStack.push('P');
    fiveStack.push('T');
    fiveStack.push('L');
    fiveStack.push('D');
    fiveStack.push('Z');

    // 6.
    std::stack<char> sixStack;
    sixStack.push('F');
    sixStack.push('B');
    sixStack.push('R');
    sixStack.push('Z');
    sixStack.push('J');
    sixStack.push('Q');
    sixStack.push('C');
    sixStack.push('D');

    // 7.
    std::stack<char> sevenStack;
    sevenStack.push('S');
    sevenStack.push('B');
    sevenStack.push('D');
    sevenStack.push('J');
    sevenStack.push('M');
    sevenStack.push('F');
    sevenStack.push('T');
    sevenStack.push('R');

    // 8.
    std::stack<char> eightStack;
    eightStack.push('L');
    eightStack.push('H');
    eightStack.push('R');
    eightStack.push('B');
    eightStack.push('T');
    eightStack.push('V');
    eightStack.push('M');

    // 9.
    std::stack<char> nineStack;
    nineStack.push('Q');
    nineStack.push('P');
    nineStack.push('D');
    nineStack.push('S');
    nineStack.push('V');

    m_CrateData.push_back(oneStack);
    m_CrateData.push_back(twoStack);
    m_CrateData.push_back(threeStack);
    m_CrateData.push_back(fourStack);
    m_CrateData.push_back(fiveStack);
    m_CrateData.push_back(sixStack);
    m_CrateData.push_back(sevenStack);
    m_CrateData.push_back(eightStack);
    m_CrateData.push_back(nineStack);
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
std::string Day5::Part1()
{
    InitializeData();

    // Read text file.
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day5Data.txt");
    std::ifstream readFile(sDataPath);
    std::string currLine;

    while (getline(readFile, currLine))
    {
        std::vector<int> vFoundNumbers;

        // Get data from line to line.
        std::string sTempString;
        bool bNumberFound = false;
        const int iCurrLineSize = static_cast<int>(currLine.size());
        for (int x = 0; x < iCurrLineSize; ++x)
        {
            const char currChar = currLine[x];
            if (isdigit(currChar))
            {
                sTempString += currChar;
                bNumberFound = true;
            }
            else if (bNumberFound)
            {
                vFoundNumbers.push_back(std::stoi(sTempString));
                sTempString = "";
                bNumberFound = false;
            }
        }

        if (!sTempString.empty())
        {
            vFoundNumbers.push_back(std::stoi(sTempString));
        }

        MovePart1(vFoundNumbers[0], vFoundNumbers[1] - 1, vFoundNumbers[2] - 1);
    }

    std::string sOutput;
    for (int x = 0; x < m_CrateData.size(); ++x)
    {
        sOutput += m_CrateData[x].top();
    }

    return sOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
std::string Day5::Part2()
{
    InitializeData();

    // Read text file.
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/Data/Day5Data.txt");
    std::ifstream readFile(sDataPath);
    std::string currLine;

    while (getline(readFile, currLine))
    {
        std::vector<int> vFoundNumbers;

        // Get data from line to line.
        std::string sTempString;
        bool bNumberFound = false;
        const int iCurrLineSize = static_cast<int>(currLine.size());
        for (int x = 0; x < iCurrLineSize; ++x)
        {
            const char currChar = currLine[x];
            if (isdigit(currChar))
            {
                sTempString += currChar;
                bNumberFound = true;
            }
            else if (bNumberFound)
            {
                vFoundNumbers.push_back(std::stoi(sTempString));
                sTempString = "";
                bNumberFound = false;
            }
        }

        if (!sTempString.empty())
        {
            vFoundNumbers.push_back(std::stoi(sTempString));
        }

        MovePart2(vFoundNumbers[0], vFoundNumbers[1] - 1, vFoundNumbers[2] - 1);
    }

    std::string sOutput;
    for (int x = 0; x < m_CrateData.size(); ++x)
    {
        sOutput += m_CrateData[x].top();
    }

    return sOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Day5::MovePart1(const int moveAmount, const int fromIndex, const int toIndex)
{
    for (int x = 0; x < moveAmount; ++x)
    {
        std::stack<char> &fromStack = m_CrateData[fromIndex];
        std::stack<char> &toStack = m_CrateData[toIndex];

        const char iTopFromItem = fromStack.top();
        toStack.push(iTopFromItem);
        fromStack.pop();
    }
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
void Day5::MovePart2(const int moveAmount, const int fromIndex, const int toIndex)
{
    std::stack<char> &fromStack = m_CrateData[fromIndex];
    std::stack<char> &toStack = m_CrateData[toIndex];

    std::vector<char> vTempCrates;

    // Grab crates from stack.
    for (int x = 0; x < moveAmount; ++x)
    {
        const char iTopFromItem = fromStack.top();
        vTempCrates.push_back(iTopFromItem);
        fromStack.pop();
    }

    // Add vTempCrates to new stack in the order they were stacked.
    for (int x = vTempCrates.size() - 1; x >= 0; --x)
    {
        toStack.push(vTempCrates[x]);
    }
}