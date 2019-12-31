#include <iostream>
#include <unordered_map>

class Solution {
public:
    int climbStairs(int n) {
        auto it = memo.find(n);
        if (it != memo.end()) {
            return it->second;
        }
        if (n == 0) {
            return 1;
        }
        int ways = 0;
        if (n >= 2) {
            ways += climbStairs(n - 2);
        }
        if (n >= 1) {
            ways += climbStairs(n - 1);
        }
        memo[n] = ways;
        return ways;
    }
private:
    std::unordered_map<int, int> memo;
};

int main() {
    Solution s;
    std::cout << s.climbStairs(44) << std::endl;
    return 0;
}