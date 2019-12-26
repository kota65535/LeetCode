#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int i = 0;
        for (int j = 0 ; j < nums.size() ; j++) {
           if (nums[i] < nums[j]) {
               nums[++i] = nums[j];
           }
        }
        return i + 1;
    }
};


int main() {
    Solution s;
    std::vector<int> v = {1, 1, 2};
    int len = s.removeDuplicates(v);
    for (int i : v) {
        std::cout << i << " " << std::endl;
    }
    std::cout << std::endl;
    std::cout << len << std::endl;
    return 0;
}