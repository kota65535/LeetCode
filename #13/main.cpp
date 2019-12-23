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

    int romanToInt(std::string s) {
        int sum = 0;
        for (int i = digits.size() - 1 ; i >= 0 ; i--) {
            for (int j = digits[i].size() - 1 ; j >= 0 ; j--) {
                if (s.find(digits[i][j]) == 0) {
                    int d = (j + 1) * std::pow(10, i);
                    int pos = digits[i][j].size();
                    sum += d;
                    s = s.substr(pos);
                    break;
                }
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::cout << s.romanToInt("IV") << std::endl;
    return 0;
}