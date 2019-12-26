#include <iostream>
#include <vector>


class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int rotated_idx = find_rorated_index(nums);
        auto it = std::lower_bound(nums.begin(), nums.begin() + rotated_idx, target);
        if (it != nums.end() && *it == target) {
            return std::distance(nums.begin(), it);
        }
        it = std::lower_bound(nums.begin() + rotated_idx, nums.end(), target);
        if (it != nums.end() && *it == target) {
            return std::distance(nums.begin(), it);
        }
        return -1;
    }

    int find_rorated_index(std::vector<int>& nums) {
        auto left = nums.begin(), right = nums.end() - 1;
        if (*left < *right) {
            return 0;
        }
        while (left <= right) {
            auto middle = left + std::distance(left, right) / 2;
            if (middle < nums.end() - 1 && *middle > *(middle + 1)) {
                return std::distance(nums.begin(), middle + 1);
            }
            if (*middle < *left) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        // not rotated
        return 0;
    }
};





int main() {
    Solution s;
    std::vector<int> v = {4, 5, 1, 2, 3};
    std::cout << s.search(v, 1) << std::endl;
    return 0;
}