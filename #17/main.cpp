#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    const std::unordered_map<char, std::vector<char>> map = {
            {'2', std::vector<char>{'a', 'b', 'c'}},
            {'3', std::vector<char>{'d', 'e', 'f'}},
            {'4', std::vector<char>{'g', 'h', 'i'}},
            {'5', std::vector<char>{'j', 'k', 'l'}},
            {'6', std::vector<char>{'m', 'n', 'o'}},
            {'7', std::vector<char>{'p', 'q', 'r', 's'}},
            {'8', std::vector<char>{'t', 'u', 'v'}},
            {'9', std::vector<char>{'w', 'x', 'y', 'z'}},
    };

    std::vector<std::string> letterCombinations(std::string digits) {

        if (digits.empty()) {
            return std::vector<std::string>();
        }

        std::vector<std::string> base(1, "");

        for (int i = 0 ; i < digits.size() ; i++) {
            std::vector<std::pair<int, int>> pairs = combination(base.size(), map.at(digits[i]).size());
            std::vector<std::string> new_base;
            for (std::pair<int, int> p : pairs) {
                new_base.push_back(base[p.first] + map.at(digits[i])[p.second]);
            }
            base = new_base;
        }
        return base;
    }

    std::vector<std::pair<int, int>> combination(int m, int n) {
        std::vector<std::pair<int, int>> pairs;
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                pairs.push_back(std::pair<int, int>(i, j));
            }
        }
        return pairs;
    }
};

int main() {
    Solution s;
    std::vector<std::string> cmb = s.letterCombinations("23");
    for (std::string s : cmb) {
        std::cout << s << std::endl;
    }
    return 0;
}