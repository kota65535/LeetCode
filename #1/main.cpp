#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> idx_map;

        for (int i=0 ; i < nums.size() ; i++) {
            int complement = target - nums[i];
            auto it = idx_map.find(complement);
            if (it != idx_map.end() && idx_map[complement] != i) {
                return std::vector<int> {i, idx_map[complement]};
            }
            idx_map[nums[i]] = i;
        }
        return std::vector<int>();
    }
};

class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> idx_map;

        for (int i=0 ; i < nums.size() ; i++) {
            idx_map[nums[i]] = i;
        }
        for (int i=0 ; i < nums.size() ; i++) {
            int complement = target - nums[i];
            auto it = idx_map.find(complement);
            if (it != idx_map.end() && idx_map[complement] != i) {
                return std::vector<int> {i, idx_map[complement]};
            }
        }
        return std::vector<int>();
    }
};

int main() {
    Solution s;
    return 0;
}