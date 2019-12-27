#include <iostream>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        // trim spaces from end
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) { return !std::isspace(ch); }).base(), s.end());
        // count characters from the last space to the end
        return std::distance(std::find_if(s.rbegin(), s.rend(), [](char c) { return std::isspace(c); }).base(), s.end());
    }
};

int main() {
    Solution s;
    std::cout << s.lengthOfLastWord("Hello ") << std::endl;
    return 0;
}