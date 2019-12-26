#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> complements;
        for (int i = 0; i < nums.size(); i++) {
            auto it = complements.find(nums[i]);
            if (it != complements.end()) {
                return std::vector<int>{i, it->second};
            } else {
                complements[target - nums[i]] = i;
            }
        }
        return std::vector<int>();
    }
};


class Solution3 {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::vector<std::pair<int, int>> pairs(nums.size());
        for (int i = 0 ; i < nums.size() ; i++) {
            pairs[i] = std::make_pair(i, nums[i]);
        }
        std::sort(pairs.begin(), pairs.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) { return p1.second < p2.second; });
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            int sum = pairs[start].second + pairs[end].second;
            if (sum == target) {
                return std::vector<int> {pairs[start].first, pairs[end].first};
            }
            if (sum < target) {
                start++;
            }
            if (sum > target) {
                end--;
            }
        }
        return std::vector<int>();
    }
};


class Pair {
public:
    Pair(int a, int b) : a(a), b(b) {}

    int a, b;
};

class Solution2 {
    std::vector<Pair> twoSumAll(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> complements;
        std::vector<Pair> ret;
        for (int i = 0 ; i < nums.size() ; i++) {
            auto it = complements.find(nums[i]);
            if (it != complements.end()) {
                ret.push_back(Pair(i, it->second));
            } else {
                complements[target - nums[i]] = i;
            }
        }
        return ret;
    }
};

int main() {
    Solution3 s;
    std::vector<int> v = {3,2,4};
    for (int p : s.twoSum(v, 6)) {
        std::cout << p << std::endl;
    }
    return 0;
}