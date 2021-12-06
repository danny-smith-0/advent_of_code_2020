#include <iostream> //std::cout
#include <fstream>  // std::ifstream
#include <string>
#include <sstream>
#include <vector>
#include <array>

#include <string_parser.h>
#include <other_aoc_utils.h>

typedef std::vector<int> ints_t;

/*
--- Day 2: Password Philosophy ---
Your flight departs in a few days from the coastal airport; the easiest way down to the coast from here is via toboggan.

The shopkeeper at the North Pole Toboggan Rental Shop is having a bad day. "Something's wrong with our computers; we can't log in!" You ask if you can take a look.

Their password database seems to be a little corrupted:
some of the passwords wouldn't have been allowed by the Official Toboggan Corporate Policy that was in effect when they were chosen.

To try to debug the problem, they have created a list (your puzzle input) of passwords (according to the corrupted database) and the corporate policy when that password was set.

For example, suppose you have the following list:

1-3 a: abcde
1-3 b: cdefg
2-9 c: ccccccccc
Each line gives the password policy and then the password.
The password policy indicates the lowest and highest number of times a given letter must appear for the password to be valid.
For example, 1-3 a means that the password must contain a at least 1 time and at most 3 times.

In the above example, 2 passwords are valid. The middle password, cdefg, is not; it contains no instances of b, but needs at least 1.
The first and third passwords are valid: they contain one a or nine c, both within the limits of their respective policies.

How many passwords are valid according to their policies?
*/

std::vector<strings_t> separate_policies_and_passwords(std::ifstream& input)
{
    std::vector<strings_t> policies_and_pwds;
    std::string line;
    std::string delimeter = ":";
    while (std::getline(input, line))
    {
        strings_t policy_and_pwd = substrings_to_strings(line, ":");
        policy_and_pwd[1].erase(0, 1); // Remove that extra space in the front
        policies_and_pwds.push_back(policy_and_pwd);
    }
    return policies_and_pwds;
}

bool check_if_password_matches_policy(strings_t policy_and_pwd)
{

    strings_t policy = substrings_to_strings(policy_and_pwd[0], " ");
    ints_t min_n_max = substrings_to_ints(policy[0], "-");
    int min = min_n_max[0];
    int max = min_n_max[1];
    char policy_char = *policy[1].c_str();

    std::string pwd = policy_and_pwd[1];
    int count = std::count(pwd.begin(), pwd.end(), policy_char);
    return count >= min && count <= max;
}

int main ()
{
    // Parse inputs
    std::ifstream input_test ("../inputs/day2_test.txt");
    std::ifstream input_real ("../inputs/day2.txt");

    // Process inputs
    std::vector<strings_t> policies_and_pwds_test = separate_policies_and_passwords(input_test);
    std::vector<strings_t> policies_and_pwds_real = separate_policies_and_passwords(input_real);

    int count_test = 0;
    int count_real = 0;
    for (auto policy_and_pwd : policies_and_pwds_test)
        count_test += check_if_password_matches_policy(policy_and_pwd) ? 1 : 0;

    for (auto policy_and_pwd : policies_and_pwds_real)
        count_real += check_if_password_matches_policy(policy_and_pwd) ? 1 : 0;

    results(count_test, 2, count_real);
    return 0;
}
