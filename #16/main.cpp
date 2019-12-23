#include <iostream>
#include <vector>



class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {

        std::sort(nums.begin(), nums.end());

        int min_diff = INT_MAX;
        int sum = -1;
        for (int i = 0 ; i < nums.size() - 2 ; i++) {
            for (int j = i + 1 ; j < nums.size() - 1 ; j++) {
                // rest value for the target
                int rest = target - nums[i] - nums[j];
                // search
                auto lb = std::lower_bound(nums.begin() + j + 1, nums.end(), rest);
                // value which is greater or equal to the rest
                int ge_rest = lb == nums.end() ? *(lb - 1) : *lb;
                // value which is less to the rest
                int lt_rest = lb == nums.begin() || lb == nums.begin() + j + 1 ? *lb : *(lb - 1);

                int this_sum = nums[i] + nums[j] + ge_rest;
                int diff = std::abs(this_sum - target);
                if (diff < min_diff) {
//                    std::cout << nums[i] << " " << nums[j] << " " << ge_rest << std::endl;
                    min_diff = diff;
                    sum = this_sum;
                }

                this_sum = nums[i] + nums[j] + lt_rest;
                diff = std::abs(this_sum - target);
                if (diff < min_diff) {
//                    std::cout << nums[i] << " " << nums[j] << " " << lt_rest << std::endl;
                    min_diff = diff;
                    sum = this_sum;
                }

                if (diff == 0) {
                    return sum;
                }
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::vector<int> input = {-1,2,1,-4};
    std::cout << s.threeSumClosest(input, 1) << std::endl;
    return 0;
}