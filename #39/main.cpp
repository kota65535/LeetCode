#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> combinations;
        // in case of single combination
        auto it = std::lower_bound(candidates.begin(), candidates.end(), target);
        if (it != candidates.end() && *it == target) {
            combinations.push_back(std::vector<int>{target});
        }
        // 2 or more combinations
        std::vector<std::vector<int>> searched = search(candidates.begin(), candidates.end(), std::vector<int>(), target);
        std::copy(searched.begin(), searched.end(), std::back_inserter(combinations));
        return combinations;
    }

    std::vector<std::vector<int>> search(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::vector<int> base, int target) {
        std::vector<std::vector<int>> combinations;
        for (auto it = begin ; it < end ; it++) {
            int rest = target - *it;
            if (rest < *it) {
                // no more available candidates
                return combinations;
            }
            // search rest value after this candidate
            auto rest_it = std::lower_bound(it, end, rest);
            if (rest_it != end && *rest_it == rest) {
                std::vector<int> entry(base);
                entry.push_back(*it);
                entry.push_back(rest);
                combinations.push_back(entry);
            }

            // prepare next candidates
            std::vector<int> next_candidates(it, end);
            // prepare next base
            std::vector<int> next_base(base);
            next_base.push_back(*it);
            // recursion
            std::vector<std::vector<int>> recursive = search(it, end, next_base, rest);
            // add the combinations
            std::copy(recursive.begin(), recursive.end(), std::back_inserter(combinations));
        }
        return combinations;
    }
};

int main() {
    Solution s;
    std::vector<int> candidates = {8,7,4,3};
    for (std::vector<int> v : s.combinationSum(candidates, 11)) {
        for (int n : v) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}