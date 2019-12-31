#include <iostream>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        auto a_it = a.rbegin();
        auto b_it = b.rbegin();
        int carry = 0;
        std::string s;
        while (a_it < a.rend() || b_it < b.rend()) {
            int a_val = 0, b_val = 0;
            if (a_it < a.rend()) {
                a_val = *a_it - '0';
            }
            if (b_it < b.rend()) {
                b_val = *b_it - '0';
            }
            int val = a_val + b_val + carry;
            carry = val / 2;
            val %= 2;

            char val_char = val + '0';
            s.insert(s.begin(), val_char);

            a_it++;
            b_it++;
        }

        if (carry == 1) {
            s.insert(s.begin(), '1');
        }
        return s;
    }
};

int main() {
    Solution s;
    std::cout << s.addBinary("1010", "1011") << std::endl;
    return 0;
}