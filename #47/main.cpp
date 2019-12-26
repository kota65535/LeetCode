
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        std::vector<int> base;
        std::sort(nums.begin(), nums.end());
        return permute_recursively(nums, base);
    }

    std::vector<std::vector<int>> permute_recursively(std::vector<int>& nums, std::vector<int>& base) {
        std::vector<std::vector<int>> ret;
        if (nums.empty()) {
            return std::vector<std::vector<int>> {base};
        }
        for (int i = 0 ; i < nums.size() ; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            std::vector<int> next_base(base);
            next_base.push_back(nums[i]);
            std::vector<int> next_nums;
            for (int j = 0 ; j < nums.size() ; j++) {
                if (j != i) {
                    next_nums.push_back(nums[j]);
                }
            }
            auto list = permute_recursively(next_nums, next_base);
            std::copy(list.begin(), list.end(), std::back_inserter(ret));
        }
        return ret;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {0,0,0,1,9};
    auto permutations = s.permuteUnique(v);
    for (auto p : permutations) {
        for (int n : p) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

