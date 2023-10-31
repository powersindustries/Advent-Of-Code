cmake_minimum_required(VERSION 2.8.12)
project(AdventOfCode)

# Set source directory to be used as path.
add_definitions(-DPROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

set(SOURCE_FILES

    main.cpp

    src/2022/Day1.h
    src/2022/Day1.cpp
    src/2022/Day2.cpp
    src/2022/Day2.h
    src/2022/Day3.cpp
    src/2022/Day3.h
    src/2022/Day4.cpp
    src/2022/Day4.h
        src/2022/Day5.cpp
        src/2022/Day5.h


)

add_executable(${PROJECT_NAME}  ${SOURCE_FILES})