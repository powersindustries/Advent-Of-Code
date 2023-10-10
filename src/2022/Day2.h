#pragma once

#include <unordered_map>
#include <vector>

enum class TurnType
{
    eRock,
    ePaper,
    eScissors
};

enum class MatchOutcomeType
{
    eWin,
    eLoss,
    eTie
};

struct MatchData
{
    TurnType m_YourTurn;
    TurnType m_EnemyTurn;

    MatchOutcomeType m_MatchOutcome;
    int m_iScore;
};

class Day2
{
public:

    Day2();

    int Part1();
    int Part2();


private:

    TurnType GetTurnTypeByOutcomeAndEnemy(MatchOutcomeType inOutcomeType, TurnType inTurnType);


private:

    // Key = TurnType to lookup, Value = TurnType key wins against.
    // EX) Key = Rock, Value = Paper.
    std::unordered_map<TurnType, TurnType> m_TurnLookupMap;

    // Part 1 data.
    std::vector<MatchData> m_Part1MatchDataVector;
    std::unordered_map<char, TurnType> m_CharToTurnTypeMap;

    // Part 2 data.
    std::vector<MatchData> m_Part2MatchDataVector;
    std::unordered_map<char, MatchOutcomeType> m_CharToMatchOutcomeMap;

};