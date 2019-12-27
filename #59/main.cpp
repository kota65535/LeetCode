#include <iostream>
#include <vector>
#include <unordered_map>

namespace std {
    template <>
    class hash<std::pair<int, int>> {
    public:
        size_t operator()(const std::pair<int, int>& x) const {
            return hash<int>()(x.first) ^ hash<int>()(x.second);
        }
    };
}

class Solution {
public:
    std::unordered_map<std::pair<int, int>, std::pair<int, int>> DIR_TABLE = {
            {{0, 1}, {1, 0}},       // right -> down
            {{1, 0}, {0, -1}},      // down -> left
            {{0, -1}, {-1, 0}},     // left -> up
            {{-1, 0}, {0, 1}}       // up -> right
    };

    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> ret(n, std::vector<int>(n, -1));
        std::pair<int, int> dir = {0, 1};
        int x = 0, y = -1;
        for (int i = 0 ; i < n * n ; i++) {
            int next_x = x + dir.first;
            int next_y = y + dir.second;
            if (next_x >= n || next_x < 0       // check row range
                || next_y >= n || next_y < 0    // check column range
                || ret[next_x][next_y] != -1    // check if already visited
                    ) {
                dir = DIR_TABLE[dir];
                next_x = x + dir.first;
                next_y = y + dir.second;
            }
            ret[next_x][next_y] = i + 1;
            x = next_x;
            y = next_y;
        }
        return ret;
    }
};

int main() {
    Solution s;
    for (auto v : s.generateMatrix(3)) {
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}