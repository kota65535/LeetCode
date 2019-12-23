#include <iostream>
#include <vector>


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        std::vector<int> digits;
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0 ; i < digits.size() / 2; i++) {
            if (digits[i] != digits[digits.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::cout << s.isPalindrome(10) << std::endl;
    return 0;
}