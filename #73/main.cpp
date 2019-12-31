#include <iostream>
#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::vector<std::pair<int, int>> zeros;
        for (int i = 0 ; i < matrix.size() ; i++) {
            for (int j = 0 ; j < matrix[0].size() ; j++) {
                if (matrix[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }
        for (auto &p : zeros) {
            // row
            for (int i = 0 ; i < matrix[p.first].size() ; i++) {
                matrix[p.first][i] = 0;
            }
            // column
            for (int i = 0 ; i < matrix.size() ; i++) {
                matrix[i][p.second] = 0;
            }
        }
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix = {
            {0,1,2,0},
            {3,4,5,2},
            {1,3,1,5}
    };

    s.setZeroes(matrix);

    for (auto v : matrix) {
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}