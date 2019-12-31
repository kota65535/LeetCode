#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> grayCode(int n) {
        if (n == 0) {
            return std::vector<int> {0};
        }
        std::vector<std::string> initial = {std::string(n, '0')};
        auto patterns = gray_code_recursive(initial, std::pow(2, n));
        std::vector<int> ret;
        for (auto s : patterns) {
            ret.push_back(binary_to_int(s));
        }
        return ret;
    }

    std::vector<std::string> gray_code_recursive(std::vector<std::string> &visited, int n) {
        std::string last = visited[visited.size() - 1];
        if (visited.size() == n) {
            if (count_diff(visited[0], last) == 1) {
                return visited;
            } else {
                return {};
            }
        }
        std::vector<std::string> variants;
        for (int i = 0 ; i < last.size() ; i++) {
            std::string variant(last);
            variant[i] = ((variant[i] - '0') ^ 1) + '0';
            auto it = std::find_if(visited.begin(), visited.end(), [&](const std::string &s) { return s == variant; });
            if (it == visited.end()) {
                variants.push_back(variant);
            }
        }
        for (std::string v : variants) {
            std::vector<std::string> next_visited(visited);
            next_visited.push_back(v);
            std::vector<std::string> patterns = gray_code_recursive(next_visited, n);
            if (! patterns.empty()) {
                return patterns;
            }
        }
        return {};
    }

    int count_diff(std::string &s1, std::string &s2) {
        int diff = 0;
        int size = std::min(s1.size(), s2.size());
        for (int i = 0 ; i < size ; i++) {
            if (s1[i] != s2[i]) {
                diff++;
            }
        }
        diff += std::abs((int)s1.size() - (int)s2.size());
        return diff;
    }

    int binary_to_int(std::string str) {
        int place = 1;
        int ret = 0;
        for (auto c = str.rbegin() ; c < str.rend() ; c++) {
            ret += (*c - '0') * place;
            place *= 2;
        }
        return ret;
    }
};

int main() {
    Solution s;
    for (int i : s.grayCode(0)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}