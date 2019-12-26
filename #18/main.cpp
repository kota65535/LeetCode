#include <iostream>
#include <vector>
#include <unordered_map>


class Triplet {
public:
    Triplet(int a, int b, int c) : a(a), b(b), c(c) {}
    int a, b, c;
};

class Pair {
public:
    Pair(int a, int b) : a(a), b(b) {}
    int a, b;
};


class Solution {
public:
    // assume sorted
    std::vector<Pair> twoSum(std::vector<int>::iterator begin, std::vector<int>::iterator end, int target) {
        std::unordered_map<int, int> complements;
        std::vector<Pair> ret;
        end--;
        while (begin < end) {
            int sum = *begin + *end;
            bool incr = false, decr = false;
            if (sum == target) {
                ret.push_back(Pair(*begin, *end));
                incr = decr = true;
            } else if (sum < target) {
                incr = true;
            } else {
                decr = true;
            }
            if (incr) {
                // increment pointer until difference value appears
                while (*begin == *(++begin) && begin < end);
            }
            if (decr) {
                // decrement pointer until difference value appears
                while (*end == *(--end) && begin < end);
            }
        }
        return ret;
    }

    // assume sorted
    std::vector<Triplet> threeSum(std::vector<int>::iterator begin, std::vector<int>::iterator end, int target) {
        std::vector<Triplet> ret;
        for (auto it = begin ; it < end ; it++) {
            if (it > begin && *it == *(it - 1)) {
                continue;
            }
            int complement = target - *it;
            std::vector<Pair> pairs = twoSum(it + 1, end, complement);
            for (Pair p : pairs) {
                ret.push_back(Triplet(*it, p.a, p.b));
            }
        }
        return ret;
    }

    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ret;
        for (int i = 0 ; i < nums.size() ; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int complement = target - nums[i];
            std::vector<Triplet> triplets = threeSum(nums.begin() + i + 1, nums.end(), complement);
            for (Triplet t : triplets) {
                ret.push_back(std::vector<int> {nums[i], t.a, t.b, t.c});
            }
        }
        return ret;
    }
};



int main() {
    Solution s;
    std::vector<int> nums = {0,0,0,0};

    for (std::vector<int> v : s.fourSum(nums, 0)) {
        for (int n : v) {
            std::cout << n  <<  " ";
        }
        std::cout << std::endl;
    }
    return 0;
}