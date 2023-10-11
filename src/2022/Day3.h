#pragma once

#include <string>
#include <vector>

class Day3
{
public:

    int Part1();
    int Part2();

private:

    char GetCommonCharTwo(const std::string& first, const std::string& second);
    char GetCommonCharThree(const std::string& first, const std::string& second, const std::string& third);

    int CalculateCommonItemsAmount(const std::vector<char>& InCommonItemsVector);
};