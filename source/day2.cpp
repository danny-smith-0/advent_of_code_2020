#include <iostream> //std::cout
#include <fstream>  // std::ifstream
#include <string>
#include <sstream>
#include <vector>
#include <array>

#include <string_parser.h>
#include <other_aoc_utils.h>

struct Policy
{
    int int0 = 0; //part1, min. part2, 1st char location (1-indexed)
    int int1 = 0; //part1, max. part2, 2nd char location (1-indexed)
    char policy_char;
    std::string pwd;

    bool count_char_match()
    {
        int count = std::count(pwd.begin(), pwd.end(), policy_char);
        return count >= int0 && count <= int1;
    }

    bool matches_only_one_location()
    {
        if (pwd.size() < int1 || pwd.size() < int0)
            return false;
        return (pwd[int0 - 1] == policy_char) ^ (pwd[int1 - 1] == policy_char);
    }
};

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

// check_if_password_matches_policy

Policy parse_policy(strings_t policy_and_pwd)
{
    strings_t policy_strings = substrings_to_strings(policy_and_pwd[0], " ");
    ints_t min_n_max = substrings_to_ints(policy_strings[0], "-");

    Policy my_policy;
    my_policy.int0 = min_n_max[0];
    my_policy.int1 = min_n_max[1];
    my_policy.policy_char = *policy_strings[1].c_str();
    my_policy.pwd = policy_and_pwd[1];
    return my_policy;
}

int count_passwords_that_match_part1(std::vector<strings_t> policies_and_pwds)
{
    int count = 0;
    for (auto policy_and_pwd : policies_and_pwds)
    {
        Policy policy = parse_policy(policy_and_pwd);
        count += policy.count_char_match() ? 1 : 0;
    }
    return count;
}

int count_passwords_that_match_part2(std::vector<strings_t> policies_and_pwds)
{
    int count = 0;
    for (auto policy_and_pwd : policies_and_pwds)
    {
        Policy policy = parse_policy(policy_and_pwd);
        count += policy.matches_only_one_location() ? 1 : 0;
    }
    return count;
}

int main ()
{
    // Parse inputs
    std::ifstream input_test ("../inputs/day2_test.txt");
    std::ifstream input_real ("../inputs/day2.txt");

    // Process inputs
    std::vector<strings_t> policies_and_pwds_test = separate_policies_and_passwords(input_test);
    std::vector<strings_t> policies_and_pwds_real = separate_policies_and_passwords(input_real);

    // Get results
    int count_test_1 = count_passwords_that_match_part1(policies_and_pwds_test);
    int count_real_1 = count_passwords_that_match_part1(policies_and_pwds_real);

    results(count_test_1, 2, count_real_1);

    int count_test_2 = count_passwords_that_match_part2(policies_and_pwds_test);
    int count_real_2 = count_passwords_that_match_part2(policies_and_pwds_real);

    results(count_test_2, 1, count_real_2);

    return 0;
}
