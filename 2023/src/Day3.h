#pragma once

#include <string>

struct SymbolLocationData
{
    SymbolLocationData(const int inLineIndex, const int inCharacterIndex, const bool bIsGear)
    {
        m_iLineIndex = inLineIndex;
        m_iCharacterIndex = inCharacterIndex;
        m_bIsGear = bIsGear;
    }

    int m_iLineIndex;
    int m_iCharacterIndex;
    bool m_bIsGear;
};

class Day3
{
public:

    Day3();

    int Part1();

    int Part2();


private:

    int GetNumberByPairPart1(const SymbolLocationData &inSymbolLocationData);
    int GetNumberByPairPart2(const SymbolLocationData &inSymbolLocationData);
    int CalculateRow(const std::string inRow, const int inIndex);

    std::vector<int> CalculateRowForGear(const std::string inRow, const int inIndex);


private:

    std::vector<std::string> m_vSchematic;
    std::vector<SymbolLocationData> m_vSymbolLocations;

};