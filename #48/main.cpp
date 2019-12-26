#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        // transpose
        for (int i = 0 ; i < matrix.size() ; i++) {
            for (int j = i ; j < matrix.size() ; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse
        for (auto &row : matrix) {
            std::reverse(row.begin(), row.end());
        }
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    Solution s;
    s.rotate(matrix);
    for (auto row : matrix) {
        for (auto i : row) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}