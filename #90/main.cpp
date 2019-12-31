#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return subsetsWithDupRecursive(nums, 0);
    }

    std::vector<std::vector<int>> subsetsWithDupRecursive(std::vector<int>& nums, int cur) {
        // no subset
        if (cur >= nums.size()) {
            return {{}};
        }
        // move forward cur until different number appears
        int next_cur = cur;
        while (next_cur < nums.size() && nums[cur] == nums[next_cur]) { next_cur++; }
        // number of this num
        int n_nums = next_cur - cur;
        std::vector<std::vector<int>> subsets;
        // get next subset by next_cur
        auto next_subsets = subsetsWithDupRecursive(nums, next_cur);
        // make subsets from this nums and the next subset
        std::vector<int> subset_base;
        for (int i = 0 ; i <= n_nums ; i++) {
            if (i != 0) {
                subset_base.push_back(nums[cur]);
            }
            for (auto ns : next_subsets) {
                std::vector<int> subset_entry(subset_base);
                std::copy(ns.begin(), ns.end(), std::back_inserter(subset_entry));
                subsets.push_back(subset_entry);
            }
        }
        return subsets;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1,2,2};
    for (auto v : s.subsetsWithDup(nums)) {
        for (int i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}