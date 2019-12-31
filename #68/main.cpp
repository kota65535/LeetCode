#include <iostream>


class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        // Newton method:
        // a = sqrt(x)
        // a^2 = x
        // f(a) = a^2 - x = 0
        // f'(a) = 2a
        // a_n+1 = a_n - f(a_n) / f'(a_n)
        double a = x;
        while (true) {
            double next_a = a - ((a * a) - x) / (2 * a);
            if (a - next_a < 0.01) {
                a = next_a;
                break;
            }
            a = next_a;
        }
        return static_cast<int>(a);
    }

    int mySqrtBinarySearch(int x) {
        // binary search
        unsigned int left = 1, right = x, mid = (left + right) / 2;
        while (left < right) {
            mid = (left + right) / 2;
            unsigned int square  = mid * mid;
            // handle overflow
            if (mid > (mid * mid) / mid) {
                right = mid;
                continue;
            }
            if (square == x) {
                break;
            }
            if (x < square) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return static_cast<int>(mid);
    }
};

int main() {
    Solution s;
    std::cout << s.mySqrt(2147395599) << std::endl;
    return 0;
}