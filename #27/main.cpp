#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int len = s.removeElement(nums, 2);
    for (int i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << len << std::endl;
    return 0;
}