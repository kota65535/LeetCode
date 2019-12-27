#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        // max subarray values that finish at i-th index
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 0 ; i < nums.size() - 1 ; i++) {
            if (nums[i+1] > dp[i] && dp[i] < 0) {
                // restart sum
                dp[i+1] = nums[i+1];
            } else {
                // add to sum
                dp[i+1] = dp[i] + nums[i+1];
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution s;
    std::vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << s.maxSubArray(v) << std::endl;
    return 0;
}