#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        int max_area = 0;
        while (right - left != 0) {
            area = (right - left) * std::min(height[left], height[right]);
            if (area > max_area) {
                max_area = area;
            }
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};

int main() {
    Solution s;
    std::vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << s.maxArea(height) << std::endl;
    return 0;
}