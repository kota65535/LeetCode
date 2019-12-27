#include <iostream>
#include <vector>
#include <numeric>
#include <sstream>


class Solution {
public:
    std::string getPermutation(int n, int k) {
        // make sequence from 1 to n
        std::vector<int> seq(n);
        std::iota(seq.begin(), seq.end(), 1);

        // make array of the number of combinations with the 1st to i-th digits is fixed
        std::vector<int> ncmb(n - 1, 1);
        for (int i = 1 ; i < n - 1 ; i++) {
            ncmb[i] *= seq[i] * ncmb[i - 1];
        }
        std::reverse(ncmb.begin(), ncmb.end());

        k--;
        std::vector<int> v;
        for (int i = 0 ; i < n - 1 ; i++) {
            int d = k / ncmb[i];
            v.push_back(seq[d]);
            seq.erase(seq.begin() + d);
            k %= ncmb[i];
        }
        v.push_back(seq[0]);

        std::ostringstream oss;
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(oss));
        return oss.str();
    }
};

int main() {
    Solution s;
    std::cout << s.getPermutation(4, 9) << std::endl;
    return 0;
}

