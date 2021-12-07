cmake_minimum_required (VERSION 3.14)
project (advent_of_code_2020)

add_subdirectory(ext/aoc_utils)

add_executable ( aoc2020
    # source/day1.cpp
    # source/day2.cpp
    source/day3.cpp
)

target_link_libraries( aoc2020
    PUBLIC
    aoc_utils
)
