#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        return combine_recursive(1, n+1, k);
    }

    std::vector<std::vector<int>> combine_recursive(int begin, int end, int k) {
        std::vector<std::vector<int>> ret;
        if (k == 1) {
            for (int i = begin ; i < end ; i++) {
                ret.push_back(std::vector<int> {i});
            }
            return ret;
        }
        for (int i = end - 1 ; i >= begin ; i--) {
            for (auto &v : combine_recursive(begin, i, k - 1)) {
                v.push_back(i);
                ret.push_back(v);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    for (auto &v : s.combine(4, 2)) {
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}