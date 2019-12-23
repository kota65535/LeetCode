#include <iostream>
#include <cmath>
#include <vector>

class Solution {
public:
    int reverse(int x) {
        bool is_negative = x < 0;

        long abs_x = std::labs(x);

        std::vector<int> digits = get_digits(abs_x);
        int ret = 0;
        for (int i = 0 ; i < digits.size() ; i++) {
            ret += digits[i] * std::pow(10, digits.size() - i - 1);
            if (ret < 0) {
                return 0;
            }
        }
        return ret * (is_negative ? -1 : 1);
    }

    std::vector<int> get_digits(long x) {
        std::vector<int> ret;
        while (x != 0) {
            ret.push_back(x % 10);
            x /= 10;
        }
        return ret;
    }
};


int main() {
    Solution s;
    int ret = s.reverse(-2147483648);
    std::cout << ret << std::endl;
    return 0;
}