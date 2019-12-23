#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    int myAtoi(std::string str) {
        // trim spaces
        ltrim(str, ' ');

        // check if negative
        bool is_negative = false;
        switch (str[0]) {
            case '-':
                is_negative = true;
            case '+':
                str.erase(0, 1);
        }
        // trim 0
        ltrim(str, '0');

        // pick number sequence
        std::vector<int> v;
        for (int i = 0 ; i < str.length() ; i++) {
            int num = str[i] - '0';
            if (0 <= num && num <= 9) {
                v.push_back(num);
                continue;
            }
            break;
        }

        if (v.size() > 10) {
            return is_negative ? INT_MIN : INT_MAX;
        }

        long ret = 0;
        for (int i = 0 ; i < v.size() ; i++) {
            ret += v[i] * std::pow(10, v.size() - i - 1) * (is_negative ? -1 : 1);
            if (ret > INT_MAX) {
                return INT_MAX;
            }
            if (ret < INT_MIN) {
                return INT_MIN;
            }
        }
        return (int) ret;
    }

    void ltrim(std::string &s, char c) {
        auto it =  std::find_if(s.begin(), s.end() , [&](char ch){ return ch != c; } );
        s.erase(s.begin() , it);
    }
};

int main() {
    Solution s;
    std::cout << s.myAtoi("42") << std::endl;
    return 0;
}