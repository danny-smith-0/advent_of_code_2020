#include <iostream> //std::cout
#include <fstream>  // std::ifstream
#include <string>
#include <vector>

#include <other_aoc_utils.h>

struct TreeGrid
{
    std::vector<std::vector<bool>> grid;
    int num_rows() { return grid.size(); }
    int num_cols() { if (grid.empty()) { return 0; } else { return grid[0].size(); } }

    TreeGrid(std::ifstream& input) { this->parse_ifstream(input); }

    void parse_ifstream(std::ifstream& input)
    {
        grid.clear();

        std::string line;
        while (std::getline(input, line))
        {
            std::vector<bool> trees;
            for (auto mychar : line)
            {
                if (mychar == '.')
                    trees.push_back(false);
                else if (mychar == '#')
                    trees.push_back(true);
                else
                    std::cout << "BAD INPUT!";
            }
            grid.push_back(trees);
        }
    }

    void print_grid()
    {
        for (auto row : grid)
        {
            for (auto tree : row)
                std::cout << ((tree) ? "#" : ".");
            std::cout << "\n";
        }
    }
};

int count_tree_collisions(TreeGrid trees, int right, int down = 1)
{
    int num_cols = trees.num_cols();
    int column = 0;

    int count = 0;
    for (int ii = down; ii < trees.num_rows(); ii += down)
    {
        column += right;
        if (column >= num_cols)
            column -= num_cols;

        count += trees.grid[ii][column] ? 1 : 0;
    }
    return count;
}

int part2(TreeGrid trees)
{
    int val1 = count_tree_collisions(trees, 1);
    int val2 = count_tree_collisions(trees, 3);
    int val3 = count_tree_collisions(trees, 5);
    int val4 = count_tree_collisions(trees, 7);
    int val5 = count_tree_collisions(trees, 1, 2);
    return val1 * val2 * val3 * val4 * val5;
}

int main ()
{
    std::ifstream input_test ("../inputs/day3_test.txt");
    std::ifstream input_real ("../inputs/day3.txt");

    TreeGrid trees_test(input_test);
    TreeGrid trees_real(input_real);

    int right = 3;
    int results_test_1 = count_tree_collisions(trees_test, right);
    int results_real_1 = count_tree_collisions(trees_real, right);

    int results_test_2 = part2(trees_test);
    int results_real_2 = part2(trees_real);

    results(results_test_1, 7, results_real_1);
    results(results_test_2, 336, results_real_2);
    return 0;
}
