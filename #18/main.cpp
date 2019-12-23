#include <iostream>
#include <vector>

class PairSum {
public:
    PairSum(int k, int l, int sum): k(k), l(l), sum(sum) {}
    int k, l, sum;
};

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {

        // pairs of all indexes and sum
        std::vector<PairSum> pair_sums;
        for (int i = 0 ; i < nums.size() ; i++) {
            for (int j = i + 1 ; j < nums.size() ; j++) {
                pair_sums.push_back(PairSum(i, j, nums[i] + nums[j]));
            }
        }

        // sort by sum
        std::sort(pair_sums.begin(), pair_sums.end(), [](const PairSum& p1, const PairSum p2) { return p1.sum < p2.sum; });

        std::vector<std::vector<int>> ret;
        for (int i = 0 ; i< nums.size() ; i++) {
            for (int j = i + 1 ; j < nums.size() ; j++) {
                // rest value for target
                int rest = target - (nums[i] + nums[j]);
                // comparator by sum
                auto cmp = [](const PairSum &p1, const PairSum &p2) { return p1.sum <  p2.sum; };
                // search all pairs whose sum is equal to the rest
                auto lb = std::lower_bound(pair_sums.begin(), pair_sums.end(), PairSum(0, 0, rest), cmp);
                auto ub = std::upper_bound(pair_sums.begin(), pair_sums.end(), PairSum(0, 0, rest), cmp);
                while (lb < ub) {
                    // the pair indexes must be greater than j to avoid dups
                    if (lb != pair_sums.end() && lb->sum == rest && j < lb->k) {
                        std::vector<int> entry = {nums[i], nums[j], nums[lb->k], nums[lb->l] };
                        std::sort(entry.begin(), entry.end());
                        ret.push_back(entry);
                    }
                    lb++;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {-3,-2,-1,0,0,1,2,3};

    for (std::vector<int> v : s.fourSum(nums, 0)) {
        for (int n : v) {
            std::cout << n  <<  " ";
        }
        std::cout << std::endl;
    }
    return 0;
}