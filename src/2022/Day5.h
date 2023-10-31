#pragma once

#include <vector>
#include <stack>
#include <string>

class Day5
{
public:

    std::string Part1();
    std::string Part2();


private:

    void InitializeData();

    void MovePart1(const int moveAmount, const int fromIndex, const int toIndex);
    void MovePart2(const int moveAmount, const int fromIndex, const int toIndex);


private:

    std::vector<std::stack<char>> m_CrateData;

};
