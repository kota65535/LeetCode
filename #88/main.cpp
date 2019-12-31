#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int cur = m+n-1;
        int cur1 = m-1;
        int cur2 = n-1;
        while (cur >= 0) {
            if (cur1 >= 0 && cur2 >= 0) {
                if (nums1[cur1] > nums2[cur2]) {
                    nums1[cur] = nums1[cur1];
                    cur1--;
                } else {
                    nums1[cur] = nums2[cur2];
                    cur2--;
                }
            } else if (cur1 >= 0) {
                nums1[cur] = nums1[cur1];
                cur1--;
            } else if (cur2 >= 0) {
                nums1[cur] = nums2[cur2];
                cur2--;
            }
            cur--;
        }
    }
};

int main() {
    Solution s;
    std::vector<int> num1 = {1,2,3,0,0,0};
    std::vector<int> num2 = {2,5,6};
    s.merge(num1, 3, num2, 3);
    for (int i : num1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}