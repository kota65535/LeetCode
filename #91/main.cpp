#include <iostream>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        std::vector<int> dp(s.size() + 1);
        dp[s.size()] = 1;

        for (int i = s.size() - 1 ; i >= 0 ; i--) {
            int n = std::atoi(s.substr(i, 1).c_str());
            if (1 <= n && n <= 9) {
                dp[i] += dp[i+1];
            }
            if (i + 2 <= s.size()) {
                n = std::atoi(s.substr(i, 2).c_str());
                if (10 <= n && n <= 26) {
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
    }

    int numDecodingsRecursive(std::string s) {
        if (s.size() == 0) {
            return 1;
        }
        int patterns = 0;
        if (s.size() >= 1) {
            int n = std::strtol(s.substr(0, 1).c_str(), nullptr, 10);
            if (1 <= n && n <= 9) {
                patterns += numDecodings(s.substr(1));
            }
        }
        if (s.size() >= 2) {
            int n = std::strtol(s.substr(0, 2).c_str(), nullptr, 10);
            if (10 <= n && n <= 26) {
                patterns += numDecodings(s.substr(2));
            }
        }
        return patterns;
    }
};

int main() {
    Solution s;
    std::cout << s.numDecodings("226") << std::endl;
    return 0;
}