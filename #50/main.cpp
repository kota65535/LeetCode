#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (n > 1) {
            return myPow(x*x, n/2) * (n % 2 == 1 ? x : 1);
        } else if (n == 1) {
            return x;
        } else if (n == 0) {
            return 1;
        } else if (n == -1) {
            return 1 / x;
        } else {
            return myPow(x*x, n/2) / (n % 2 == -1 ? x : 1);
        }
    }
};

int main() {
    Solution s;
    double a = s.myPow(2.000, -3);
    std::cout << a << std::endl;
}