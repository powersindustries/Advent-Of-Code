cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(AdventOfCode)

# Set source directory to be used as path.
add_definitions(-DPROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

set(SOURCE_FILES

        main.cpp

        src/Day1.h
        src/Day1.cpp
        src/Day2.cpp
        src/Day2.h
        src/Day3.cpp
        src/Day3.h
        src/Day4.cpp
        src/Day4.h
        src/Day5.cpp
        src/Day5.h
        src/Day6.cpp
        src/Day6.h


)

add_executable(${PROJECT_NAME}  ${SOURCE_FILES})