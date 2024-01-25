#include <iostream>
#include "src/Day1.h"
#include "src/Day2.h"
#include "src/Day3.h"

int main()
{
    std::cout << "Advent of Code!" << std::endl;

    // Advent of Code Solutions for 2023.

    // Day 1 Solution.
    std::cout << "Day 1" << std::endl;

    Day1 day1;
    std::cout << "Part 1: " << day1.Part1() << std::endl;
    std::cout << "Part 2: " << day1.Part2() << std::endl;
    std::cout << std::endl;

    // Day 2 Solution.
    std::cout << "Day 2" << std::endl;

    Day2 day2;
    std::cout << "Part 1: " << day2.Part1() << std::endl;
    std::cout << "Part 2: " << day2.Part2() << std::endl;
    std::cout << std::endl;

    // Day 3 Solution.
    std::cout << "Day 3" << std::endl;

    Day3 day3;
    std::cout << "Part 1: " << day3.Part1() << std::endl;
    std::cout << "Part 2: " << day3.Part2() << std::endl;
    std::cout << std::endl;

    return 0;
}
