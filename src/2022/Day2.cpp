#include "Day2.h"
#include <string>
#include <fstream>


#define TIE_AMOUNT 3
#define WIN_AMOUNT 6


// ----------------------------------------------------------------
// ----------------------------------------------------------------
Day2::Day2()
{
    m_CharToTurnTypeMap['A'] = TurnType::eRock;
    m_CharToTurnTypeMap['B'] = TurnType::ePaper;
    m_CharToTurnTypeMap['C'] = TurnType::eScissors;
    m_CharToTurnTypeMap['X'] = TurnType::eRock;
    m_CharToTurnTypeMap['Y'] = TurnType::ePaper;
    m_CharToTurnTypeMap['Z'] = TurnType::eScissors;

    m_TurnLookupMap[TurnType::eRock] = TurnType::eScissors;
    m_TurnLookupMap[TurnType::ePaper] = TurnType::eRock;
    m_TurnLookupMap[TurnType::eScissors] = TurnType::ePaper;

    m_CharToMatchOutcomeMap['X'] = MatchOutcomeType::eLoss;
    m_CharToMatchOutcomeMap['Y'] = MatchOutcomeType::eTie;
    m_CharToMatchOutcomeMap['Z'] = MatchOutcomeType::eWin;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day2::Part1()
{
    // Read text file.
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/2022/Data/Day2Data.txt");
    std::ifstream readFile(sDataPath);
    std::string currLine;

    while (getline(readFile, currLine))
    {
        MatchData newMatchData;

        // Set m_EnemyTurn and m_YourTurn data fields.
        const int currLineSize = static_cast<int>(currLine.size());
        for(int x=0; x < currLineSize; ++x)
        {
            const char currChar = currLine[x];
            if(currChar == 'A' || currChar == 'B' || currChar == 'C')
            {
                newMatchData.m_EnemyTurn = m_CharToTurnTypeMap[currChar];
            }
            else if (currChar == 'X' || currChar == 'Y' || currChar == 'Z')
            {
                newMatchData.m_YourTurn = m_CharToTurnTypeMap[currChar];
            }
            else
            {
                continue;
            }
        }

        // Set m_MatchOutcome.
        if (newMatchData.m_YourTurn == newMatchData.m_EnemyTurn)
        {
            newMatchData.m_MatchOutcome = MatchOutcomeType::eTie;
        }
        else if (m_TurnLookupMap[newMatchData.m_YourTurn] == newMatchData.m_EnemyTurn)
        {
            newMatchData.m_MatchOutcome = MatchOutcomeType::eWin;
        }
        else
        {
            newMatchData.m_MatchOutcome = MatchOutcomeType::eLoss;
        }

        // Set m_iScore.
        newMatchData.m_iScore = static_cast<int>(newMatchData.m_YourTurn) + 1;

        if(newMatchData.m_MatchOutcome == MatchOutcomeType::eWin){
            newMatchData.m_iScore += WIN_AMOUNT;
        }
        else if (newMatchData.m_MatchOutcome == MatchOutcomeType::eTie)
        {
            newMatchData.m_iScore += TIE_AMOUNT;
        }

        // Add to m_Part1MatchDataVector.
        m_Part1MatchDataVector.push_back(newMatchData);
    }

    // Calculate total score.
    const int iMatchDataVectorSize = static_cast<int>(m_Part1MatchDataVector.size());
    int iOutput = 0;

    for(int x=0; x<iMatchDataVectorSize; ++x)
    {
        iOutput += m_Part1MatchDataVector[x].m_iScore;
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
int Day2::Part2()
{
    // Read text file.
    std::string sDataPath = PROJECT_PATH;
    sDataPath.append("/src/2022/Data/Day2Data.txt");
    std::ifstream readFile(sDataPath);
    std::string currLine;

    while (getline(readFile, currLine))
    {
        MatchData newMatchData;

        // Set m_EnemyTurn and m_YourTurn data fields.
        const int currLineSize = static_cast<int>(currLine.size());
        for(int x=0; x < currLineSize; ++x)
        {
            const char currChar = currLine[x];
            if(currChar == 'A' || currChar == 'B' || currChar == 'C')
            {
                newMatchData.m_EnemyTurn = m_CharToTurnTypeMap[currChar];
            }
            else if (currChar == 'X' || currChar == 'Y' || currChar == 'Z')
            {
                newMatchData.m_MatchOutcome = m_CharToMatchOutcomeMap[currChar];
            }
            else
            {
                continue;
            }
        }

        // Set m_YourTurn.
        newMatchData.m_YourTurn = GetTurnTypeByOutcomeAndEnemy(newMatchData.m_MatchOutcome, newMatchData.m_EnemyTurn);

        // Set m_iScore.
        newMatchData.m_iScore = static_cast<int>(newMatchData.m_YourTurn) + 1;

        if(newMatchData.m_MatchOutcome == MatchOutcomeType::eWin){
            newMatchData.m_iScore += WIN_AMOUNT;
        }
        else if (newMatchData.m_MatchOutcome == MatchOutcomeType::eTie)
        {
            newMatchData.m_iScore += TIE_AMOUNT;
        }

        // Add to m_Part2MatchDataVector.
        m_Part2MatchDataVector.push_back(newMatchData);
    }

    // Calculate total score.
    const int iMatchDataVectorSize = static_cast<int>(m_Part2MatchDataVector.size());
    int iOutput = 0;

    for(int x=0; x<iMatchDataVectorSize; ++x)
    {
        iOutput += m_Part2MatchDataVector[x].m_iScore;
    }

    return iOutput;
}


// ----------------------------------------------------------------
// ----------------------------------------------------------------
TurnType Day2::GetTurnTypeByOutcomeAndEnemy(const MatchOutcomeType inOutcomeType, TurnType inTurnType)
{
    switch (inOutcomeType)
    {
        case MatchOutcomeType::eLoss :
        {
            return m_TurnLookupMap[inTurnType];
        }
        case MatchOutcomeType::eWin :
        {
            TurnType tempTurnType = m_TurnLookupMap[inTurnType];
            return m_TurnLookupMap[tempTurnType];
        }
        case MatchOutcomeType::eTie :
        default:
        {
            return inTurnType;
        }
    }
}
