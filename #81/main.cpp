#include <iostream>
#include <vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return false;
        }
        int pos = find_rotated_position(nums);
        auto it = std::lower_bound(nums.begin(), nums.begin() + pos + 1, target);
        if (it != nums.end() && *it == target) {
            return true;
        }
        it = std::lower_bound(nums.begin() + pos + 1, nums.end(), target);
        if (it != nums.end() && *it == target) {
            return true;
        }
        return false;
    }

    int find_rotated_position(std::vector<int>& nums) {
        int left = -1, right = nums.size();
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            int close_left = std::max(left, 0);
            int close_right = std::min(right, (int)nums.size() -1);
            if (nums[close_left] < nums[mid]) {
                left = mid;
            } else if (nums[mid] < nums[close_left]) {
                right = mid;
            } else {
                left = close_left;
                while (left + 1 <= close_right && nums[left] <= nums[left+1]) { left++; }
                break;
            }
        }
        return left;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {3, 1};
    std::cout << s.search(nums, 1) << std::endl;
    return 0;
}