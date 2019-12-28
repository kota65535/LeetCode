#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        memo = new std::vector<std::vector<int>>(obstacleGrid.size(), std::vector<int>(obstacleGrid[0].size(), -1));
        return find_path(obstacleGrid, obstacleGrid.size() - 1, obstacleGrid[0].size() - 1);
    }

private:
    std::vector<std::vector<int>> *memo;

    int find_path(std::vector<std::vector<int>> &grid, int a , int b) {
        int m = grid.size();
        int n = grid[0].size();
        // cannot move!
        if (grid[m-a-1][n-b-1] == 1) {
            return 0;
        }
        // goal is here
        if (a == 0 && b == 0) {
            return 1;
        }
        auto &ref = *memo;
        if (ref[a][b] != -1) {
            return ref[a][b];
        }
        int paths = 0;
        // downward
        if (a > 0 && grid[m-a][n-b-1] == 0) {
            paths += find_path(grid, a - 1, b);
        }
        // rightward
        if (b > 0 && grid[m-a-1][n-b] == 0) {
            paths += find_path(grid, a, b - 1);
        }
        ref[a][b] = paths;
        return paths;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = {
            {1,0}
    };
    std::cout << s.uniquePathsWithObstacles(grid) << std::endl;
    return 0;
}