#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        // sort by start position
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &v1, const std::vector<int> &v2) { return v1[0] < v2[0]; });

        int pos = 0;
        std::vector<int> current = intervals[0];
        std::vector<std::vector<int>> ret;
        while (pos < intervals.size()) {
            if (current[1] >= intervals[pos][1]) {
                // current contains target, do nothing
            } else if (current[1] >= intervals[pos][0]) {
                // merge current and target
                current = {current[0], intervals[pos][1]};
            } else {
                // no need to merge, add to ret
                ret.push_back(current);
                current = intervals[pos];
            }
            pos++;
        }
        ret.push_back(current);

        return ret;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> v = {
            {1,3}
    };

    for (auto mv : s.merge(v)) {
        for (auto i : mv) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}