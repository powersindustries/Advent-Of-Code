#pragma once

#include <vector>

class Day1
{
public:

    Day1();

    int Part1();
    int Part2();


private:

    // Returns True if a substring was found.
    bool ReplaceWord(std::string& inFullString, const std::string& inSubstring);


private:

    std::vector<std::string> m_vNumberWordVector;

};