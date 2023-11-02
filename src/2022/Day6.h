#pragma once

#include <string>

class Day6
{
public:

    Day6();

    int Part1();
    int Part2();


private:

    int FindMarker(const int inMarkerSize);


private:

    std::string m_sPacket;

};