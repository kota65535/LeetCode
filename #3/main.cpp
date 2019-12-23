#include <iostream>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        const int length = s.length();
        if (length == 1) {
            return 1;
        }
        int start = 0, end = 1, max_len = 0;
        std::unordered_map<char, int> chars;
        chars[s[start]] = 1;
        while (end < length) {
            auto it = chars.find(s[end]);
            if (it != chars.end()) {
                // found
                chars.erase(s[start]);
                start++;
            } else {
                // not found
                chars[s[end]] = 1;
                end++;
                int current_len = end - start;
                if (max_len < current_len) {
                    max_len = current_len;
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution s;
    int i = s.lengthOfLongestSubstring(std::string("abcabcbb"));
    std::cout << i << std::endl;
    return 0;
}