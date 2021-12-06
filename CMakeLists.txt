cmake_minimum_required (VERSION 3.14)
project (advent_of_code_2020)

add_executable ( aoc2020
    # source/day1.cpp
    source/day2.cpp
)

target_include_directories ( aoc2020
    PUBLIC
    include
)