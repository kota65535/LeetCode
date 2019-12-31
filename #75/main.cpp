#include <iostream>
#include <vector>

class QuickSort {
    void sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        if (begin >= end) {
            return;
        }
        auto pivot = choose_pivot(begin, end);
        auto part = partition(pivot, begin, end);
        sort(begin, part);
        sort(part + 1, end);
    }

    std::vector<int>::iterator choose_pivot(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        return begin;
    }

    std::vector<int>::iterator partition(std::vector<int>::iterator pivot, std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        std::cout << "begin partition" << std::endl;
        print(begin, end);
        std::cout << std::string(std::distance(begin, pivot) * 2, ' ') << 'p' << std::endl;

        int pivot_value = *pivot;
        // save pivot to right end
        std::swap(*pivot, *(end - 1));
        // move smaller values than pivot
        auto partition = begin;
        for (auto it = begin ; it < end - 1; it++) {
            if (*it <= pivot_value) {
                std::swap(*partition, *it);
                partition++;
            }
        }
        // restore pivot
        std::swap(*partition, *(end - 1));

        print(begin, end);
        std::cout << std::string(std::distance(begin, partition) * 2, ' ') << '|' << std::endl;
        std::cout << "end partition" << std::endl;
        return partition;
    }

    void print(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
        for (auto it = begin ; it < end ; it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};


class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int cur = 0;
        int p = 0;
        int q = nums.size() - 1;

//        print(nums, cur, p, q);
        while (cur <= q) {
            if (nums[cur] == 0) {
                std::swap(nums[cur], nums[p]);
                p++;
                cur++;
            } else if (nums[cur] == 2) {
                std::swap(nums[cur], nums[q]);
                q--;
            } else {
                cur++;
            }
//            print(nums, cur, p, q);
        }
    }

    void print(std::vector<int> &nums, int cur, int p, int q) {
        for (int n : nums) {
            std::cout << n << "  ";
        }
        std::cout << std::endl;
        for (int i = 0 ; i < nums.size() ; i++) {
            std::string s;
            if (i == cur) {
                s += "c";
            }
            if (i == p) {
                s += "p";
            }
            if (i == q) {
                s += "q";
            }
            if (s.size() < 3) {
                s += std::string(3 - s.size(), ' ');
            }
            std::cout << s;
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1, 2, 0};
    s.sortColors(v);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}