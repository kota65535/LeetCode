#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::vector<int> base;
        return permute_recursively(nums, base);
    }

    std::vector<std::vector<int>> permute_recursively(std::vector<int> &nums, int start, int end) {
        std::vector<std::vector<int>> ret;
        if (start == end) {
            return std::vector<std::vector<int>>{nums};
        } else {
            for (int i = start; i < end; i++) {
                std::swap(nums[start], nums[i]);
                auto pr = permute_recursively(nums, start + 1, end);
                std::copy(pr.begin(), pr.end(), std::back_inserter(ret));
                std::swap(nums[i], nums[start]);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1,2,3};
    auto permutations = s.permute(v);
    for (auto p : permutations) {
        for (int n : p) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}