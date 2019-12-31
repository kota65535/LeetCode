#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1;
        for(auto it = digits.rbegin() ; it < digits.rend() ; it++) {
            *it += carry;
            carry = *it / 10;
            *it %= 10;
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1, 2, 3, 9};
    for (int i : s.plusOne(v)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}