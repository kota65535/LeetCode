#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        // find index of peak
        int peak_idx = nums.size() - 1;
        while (peak_idx >= 1 && nums[peak_idx] <= nums[peak_idx - 1]) {
            peak_idx--;
        }
        // if peak is the left end, return the first permutation
        if (peak_idx == 0) {
            std::sort(nums.begin(), nums.end());
            return;
        }
        // find min number from the numbers which is larger than num[peak_idx-1]
        int greater_min = nums[peak_idx];
        int swapped_idx = peak_idx;
        for (int i = peak_idx ; i < nums.size() ; i++) {
            if (nums[i] > nums[peak_idx - 1] && nums[i] < greater_min) {
                greater_min = nums[i];
                swapped_idx = i;
            }
        }

        std::swap(nums[peak_idx - 1], nums[swapped_idx]);
        std::sort(nums.begin() + peak_idx, nums.end());
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1};
    s.nextPermutation(v);
    for (int n : v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}