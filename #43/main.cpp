#include <iostream>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        std::string ret = "0";
        for (int i = num2.size() - 1 ; i >= 0; i--) {
            std::string digit_sum = "0";
            for (int j = num1.size() - 1 ; j >= 0 ; j--) {
                int mult = std::stoi(std::string {num1[j]}) * std::stoi(std::string {num2[i]});
                std::string mult_str = std::to_string(mult);
                if (mult_str != "0") {
                    std::string zeros(num1.size() - j - 1, '0');
                    mult_str += zeros;
                }
                digit_sum = add(digit_sum, mult_str);
            }
            if (digit_sum != "0") {
                std::string zeros(num2.size() - i - 1, '0');
                digit_sum += zeros;
            }

            ret = add(ret, digit_sum);
        }
        return ret;
    }

    // add operation for two string
    std::string add(std::string num1, std::string num2) {
        std::string ret;
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        int carry = 0;
        int max_digits = std::max(num1.size(), num2.size());
        for (int i = 0 ; i < max_digits ; i++) {
            int d1 = i < num1.size() ? num1[i] - '0' : 0;
            int d2 = i < num2.size() ? num2[i] - '0' : 0;
            int added = d1 + d2 + carry;
            ret.insert(ret.begin(), (added % 10) + '0');
            carry = added / 10;
        }
        if (carry > 0) {
            ret.insert(ret.begin(), '1');
        }
        return ret;
    }
};

int main() {
    Solution s;
    std::cout << s.multiply("0", "52") << std::endl;
    return 0;
}