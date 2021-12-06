#include <iostream> //std::cout
#include <fstream>  // std::ifstream
#include <string>
#include <sstream>
#include <vector>

#include <string_parser.h>
#include <other_aoc_utils.h>

typedef std::vector<int> ints_t;

/*
--- Day 1: Report Repair ---
After saving Christmas five years in a row, you've decided to take a vacation at a nice resort on a tropical island. Surely, Christmas will go on without you.
The tropical island has its own currency and is entirely cash-only. The gold coins used there have a little picture of a starfish; the locals just call them stars.
None of the currency exchanges seem to have heard of them, but somehow, you'll need to find fifty of these coins by the time you arrive so you can pay the deposit on your room.
To save your vacation, you need to get all fifty stars by December 25th.
Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!
Before you leave, the Elves in accounting just need you to fix your expense report (your puzzle input); apparently, something isn't quite adding up.
Specifically, they need you to find the two entries that sum to 2020 and then multiply those two numbers together.
For example, suppose your expense report contained the following:

1721
979
366
299
675
1456

In this list, the two entries that sum to 2020 are 1721 and 299. Multiplying them together produces 1721 * 299 = 514579, so the correct answer is 514579.
Of course, your expense report is much larger. Find the two entries that sum to 2020; what do you get if you multiply them together?

--- Part Two ---
The Elves in accounting are thankful for your help; one of them even offers you a starfish coin they had left over from a past vacation. They offer you a second one if you can find three numbers in your expense report that meet the same criteria.
Using the above example again, the three entries that sum to 2020 are 979, 366, and 675. Multiplying them together produces the answer, 241861950.
In your expense report, what is the product of the three entries that sum to 2020?
*/

size_t product_of_two_entries_that_sum_to_2020(ints_t entries)
{
    for (size_t ii = 0; ii < entries.size(); ++ii)
        for (size_t jj = ii + 1; jj < entries.size(); ++jj)
            if (entries[ii] + entries[jj] == 2020)
                return entries[ii] * entries[jj];
    return 0;
}

size_t product_of_three_entries_that_sum_to_2020(ints_t entries)
{
    for (size_t ii = 0; ii < entries.size(); ++ii)
        for (size_t jj = ii + 1; jj < entries.size(); ++jj)
            for (size_t kk = ii + 2; kk < entries.size(); ++kk)
                if (entries[ii] + entries[jj] + entries[kk] == 2020)
                    return entries[ii] * entries[jj] * entries[kk];
    return 0;
}
int main ()
{
    // Parse inputs
    std::ifstream test_input ("../inputs/day1_test.txt");
    std::ifstream input ("../inputs/day1.txt");

    ints_t entries, test_entries;
    std::string line;
    while (std::getline( input, line))
        entries.push_back(std::stoi(line));
    while (std::getline( test_input, line))
        test_entries.push_back(std::stoi(line));

    // Part 1
    size_t test_result1 = product_of_two_entries_that_sum_to_2020(test_entries);
    std::cout << "Test result 1 is " << test_result1;
    if (test_result1 == 514579) { std::cout << ". Passed!\n"; } else { std::cout << ". Whoops.\n"; }
    std::cout << "Real result 1 is " << product_of_two_entries_that_sum_to_2020(entries) << std::endl;

    // Part 2
    size_t test_result2 = product_of_three_entries_that_sum_to_2020(test_entries);
    std::cout << "Test result 2 is " << test_result2;
    if (test_result2 == 241861950) { std::cout << ". Passed!\n"; } else { std::cout << ". Whoops.\n"; }
    std::cout << "Real result 2 is " << product_of_three_entries_that_sum_to_2020(entries) << std::endl;

    return 0;
}
