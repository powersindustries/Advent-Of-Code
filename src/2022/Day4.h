#pragma once

#include <vector>

struct SectionData
{
    int m_iStart;
    int m_iEnd;
};

class SectionDataPairs
{
public:

    SectionDataPairs(SectionData inFirst, SectionData inSecond)
    {
        m_First = inFirst;
        m_Second = inSecond;
    }


public:

    SectionData m_First;
    SectionData m_Second;

};

class Day4
{
public:

    int Part1();
    int Part2();

private:

    bool PairContainsPair(SectionData inLeft, SectionData inRight);
    bool PairsOverlap(SectionData inLeft, SectionData inRight);


private:

    std::vector<SectionDataPairs> m_SectionDataPairsVector;

};