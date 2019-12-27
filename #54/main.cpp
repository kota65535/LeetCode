#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return std::vector<int>();
        }
        std::vector<std::vector<bool>> visited(matrix.size(), std::vector<bool>(matrix[0].size(), false));
        int length = matrix[0].size() * matrix.size();
        std::vector<int> ret;
        int n_dir = 0, m_dir = 1;
        int x = 0, y = -1;
        for (int i = 0 ; i < length ; i++) {
            int next_x = x + n_dir;
            int next_y = y + m_dir;
            if (next_x >= matrix.size()
                || next_y >= matrix[x].size()
                || visited[next_x][next_y]) {

                if (n_dir == 0 && m_dir == 1) {
                    // right -> down
                    n_dir = 1;
                    m_dir = 0;
                } else if (n_dir == 1 && m_dir == 0) {
                    // down -> left
                    n_dir = 0;
                    m_dir = -1;
                } else if (n_dir == 0 && m_dir == -1) {
                    // left -> up
                    n_dir = -1;
                    m_dir = 0;
                } else if (n_dir == -1 && m_dir == 0) {
                    // up -> right
                    n_dir = 0;
                    m_dir = 1;
                }
                next_x = x + n_dir;
                next_y = y + m_dir;
            }
            ret.push_back(matrix[next_x][next_y]);
            visited[next_x][next_y] = true;
            x = next_x;
            y = next_y;
        }
        return ret;
    }
};


int main() {
    Solution s;
    std::vector<std::vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    for (int i : s.spiralOrder(matrix)) {
        std::cout << i << std::endl;
    }
    return 0;
}