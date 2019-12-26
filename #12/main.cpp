#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    const std::vector<std::string> digit1 = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
    const std::vector<std::string> digit10 = { "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    const std::vector<std::string> digit100 = { "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    const std::vector<std::string> digit1000 = { "M", "MM", "MMM"};
    const std::vector<std::vector<std::string>> digits = { digit1, digit10, digit100, digit1000 };

    std::string intToRoman(int num) {
        std::string ret;
        for (int i = digits.size() - 1 ; i >= 0 ; i--) {
            int divisor = std::pow(10, i);
            int digit = num / divisor;
            if (digit >= 1) {
                ret += digits[i][digit - 1];
            }
            num %= divisor;
        }
        return ret;
    }
};

int main() {

    Solution s;
    std::cout << s.intToRoman(1994) << std::endl;
    return 0;
}