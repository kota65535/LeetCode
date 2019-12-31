#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> bit_cmb = bit_combinations(nums.size());
        std::vector<std::vector<int>> ret;
        for (auto &cmb : bit_cmb) {
            std::vector<int> entry;
            for (int i = 0 ; i < cmb.size() ; i++) {
                if (cmb[i]) {
                    entry.push_back(nums[i]);
                }
            }
            ret.push_back(entry);
        }
        return ret;
    }

    std::vector<std::vector<int>> bit_combinations(int n) {
        std::vector<std::vector<int>> ret;
        if (n == 1) {
            return {{0}, {1}};
        }
        for (auto &v : bit_combinations(n - 1)) {
            std::vector<int> v0(v), v1(v);
            v0.push_back(0);
            ret.push_back(v0);
            v1.push_back(1);
            ret.push_back(v1);
        }
        return ret;
    }
};

int main() {
    Solution s;
    std::vector<int> v {1,2,3};
    for (auto v : s.subsets(v)) {
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}