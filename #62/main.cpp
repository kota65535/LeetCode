#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> *memo;

    int uniquePaths(int m, int n) {
        memo = new std::vector<std::vector<int>>(m, std::vector<int>(n, -1));
        return find_path(m, n);
    }

    int find_path(int m, int n) {
        // no path anymore
        if (m == 0 || n == 0) {
            return 0;
        }
        // goal is here
        if (m == 1 && n == 1) {
            return 1;
        } else {
            auto &ref = *memo;
            if (ref[m-1][n-1] != -1) {
                return ref[m-1][n-1];
            }
            int paths = find_path(m - 1, n) + find_path(m, n - 1);
            ref[m-1][n-1] = paths;
            if (n < ref.size() && m < ref[n].size()) {
                ref[n-1][m-1] = paths;
            }

            return paths;
        }
    }
};

int main() {
    Solution s;
    std::cout << s.uniquePaths(23, 12) << std::endl;
    return 0;
}