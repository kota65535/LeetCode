#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_negative = (dividend < 0) ^ (divisor < 0);

        long l_dividend = std::labs(dividend);
        long l_divisor = std::labs(divisor);

        long ret = 0;
        int n_bits = sizeof(int) * 8;
        for (int i = n_bits - 1 ; i >= 0 ; i--) {
            if ((l_divisor << i) <= l_dividend) {
                l_dividend -= l_divisor << i;
                ret |= 1L << i;
            }
        }
        ret = is_negative ? -ret : ret;

        if (ret > std::numeric_limits<int>::max()) {
            ret =  std::numeric_limits<int>::max();
        }
        return static_cast<int>(ret);
    }
};

int main() {
    Solution s;
    std::cout << s.divide(-2147483648, -1) << std::endl;
    return 0;
}