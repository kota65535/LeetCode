#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int begin = -1;
        // the first position that the number is equal to target
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && *it == target) {
            begin = std::distance(nums.begin(), it);
        }
        int end = -1;
        // the first position that the number is greater than target
        it = std::upper_bound(nums.begin(), nums.end(), target);
        if (it != nums.begin() && *(it - 1) == target) {
            end = std::distance(nums.begin(), it - 1);
        }
        return std::vector<int>{begin, end};
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {5,7,7,8,8,10};
    std::vector<int> ret = s.searchRange(nums, 5);
    for (int n : ret) {
        std::cout <<  n << std::endl;
    }
    return 0;
}