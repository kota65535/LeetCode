#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() ==0) {
            return 0;
        }
        std::unordered_map<int, int> counts;
        int length = nums.size();
        // append dummy entry to omit range check
        nums.push_back(nums[nums.size()-1]);
        int offset = 0;
        for (int i = 0 ; i < length ; i++) {
            nums[i] = nums[i+offset];
            if (counts[nums[i]] >= 2) {
                while (i+offset < length && nums[i] == nums[i + offset]) { offset++; }
                nums[i] = nums[i+offset];
            }
            counts[nums[i]]++;
        }
        return length - offset;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1,1,1,2,2,3};
    std::cout << s.removeDuplicates(v) << std::endl;
    return 0;
}