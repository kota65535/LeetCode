#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        // column 1 vector
        std::vector<int> col1(matrix.size());
        std::transform(matrix.begin(), matrix.end(), col1.begin(), [](const std::vector<int> &v) { return v[0]; });
        // search target from column 1
        auto it = std::lower_bound(col1.begin(), col1.end(), target);
        if (it != col1.end() && *it == target) {
            // found
            return true;
        }
        // the row index to search
        int row = std::distance(col1.begin(), it) - 1;
        if (row < 0) {
            return false;
        }
        it = std::lower_bound(matrix[row].begin(), matrix[row].end(), target);
        return it != matrix[row].end() && *it == target;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix = {{1}};
    std::cout << s.searchMatrix(matrix, 0) << std::endl;
    return 0;
}