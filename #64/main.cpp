#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        sums = new std::vector<std::vector<long>>(grid.size(), std::vector<long>(grid[0].size(), INT_MAX));
        (*sums)[0][0] = grid[0][0];
        m = grid.size();
        n = grid[0].size();
        find_path(grid, m-1, n-1);
        return (*sums)[m-1][n-1];
    }

private:
    std::vector<std::vector<long>> *sums;
    int m , n;

    void find_path(std::vector<std::vector<int>>& grid, int a, int b) {
        // goal is here, stop recursion
        if (a == 0 && b == 0) {
            return;
        }
        // rightward
        if (a > 0) {
            long new_sum = (*sums)[m - a - 1][n - b - 1] + grid[m - a][n - b - 1];
            if (new_sum < (*sums)[m - a][n - b - 1]) {
                // update sum and continue to find
                (*sums)[m - a][n - b - 1] = new_sum;
                find_path(grid, a - 1, b);
            }
        }
        // downward
        if (b > 0) {
            long new_sum = (*sums)[m - a - 1][n - b - 1] + grid[m - a - 1][n - b];
            if (new_sum < (*sums)[m - a - 1][n - b]) {
                // update sum and continue to find
                (*sums)[m - a -1][n - b] = new_sum;
                find_path(grid, a, b - 1);
            }
        }
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = {
            {1,3,1},
            {1,5,1},
            {4,2,1}
    };
    std::cout << s.minPathSum(grid) << std::endl;
    return 0;
}