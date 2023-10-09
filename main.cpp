#include <iostream>
#include <vector>
#include "src/2022/Day1.h"

int main()
{
    std::cout << "Advent of Code!" << std::endl;

    // 2022 Advent of Code.

    // Day 1 Solution.
    std::vector<int> vCalorieVector;
    Day1::Part1(vCalorieVector);

    std::cout << "Part 1 Solution: " << vCalorieVector[0] << std::endl;
    std::cout << "Part 2 Solution: " << Day1::Part2(vCalorieVector) << std::endl;

    return 0;
}
