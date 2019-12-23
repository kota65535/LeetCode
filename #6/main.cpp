#include <iostream>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (s.empty()) {
            return "";
        }
        if (numRows == 1) {
            return s;
        }
        int cycle = (numRows - 1) * 2;
        std::vector<std::string> strs(cycle, "");
        for (int i = 0 ; i < cycle ; i++) {
            int pos = i;
            while (pos < s.length()) {
                strs[i] += s[pos];
                pos += cycle;
            }
        }
        std::string ret;
        ret += strs[0];
        for (int i = 1 ; i < numRows - 1 ; i++) {
            int j = (numRows - 1) * 2 - i;
            for (int k = 0 ; k < strs[j].length() ; k++ ) {
                ret += strs[i][k];
                ret += strs[j][k];
            }
            if (strs[i].length() > strs[j].length()) {
                ret += strs[i].back();
            }
        }
        ret += strs[numRows - 1];
        return ret;
    }
};

int main() {
    Solution s;
    std::string ans = s.convert("ABCD", 2);
    std::cout << ans << std::endl;
    return 0;
}