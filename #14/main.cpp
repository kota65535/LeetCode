#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        // map size of each string
        std::vector<int> lengths(strs.size());
        std::transform(strs.begin(), strs.end(), lengths.begin(), [](const std::string& s) { return s.size(); });
        // get min length of strings
        int min_length = *std::min_element(lengths.begin(), lengths.end());

        std::string prefix;
        for (int i = 0 ; i < min_length ; i++) {
            char c = strs[0][i];
            // map i'th character of each string
            std::vector<char> ith_chars(strs.size());
            std::transform(strs.begin(), strs.end(), ith_chars.begin(), [&](const std::string& s) { return s[i]; });
            // check all characters equal
            if (std::equal(ith_chars.begin() + 1, ith_chars.end(), ith_chars.begin())) {
                // if equal, append it
                prefix += c;
            } else {
                // if not, finish
                break;
            }
        }
        return prefix;
    }
};

int main() {
    Solution s;
    std::vector<std::string> list = {"aca", "cba"};
    std::cout << s.longestCommonPrefix(list) << std::endl;
    return 0;
}
