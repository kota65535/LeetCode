#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *less_head, *less_cur, *greater_head, *greater_cur;
        less_head = less_cur = greater_head = greater_cur = nullptr;
        if (head->val < x) {
            less_head = less_cur = head;
        } else {
            greater_head = greater_cur = head;
        }
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            if (cur->val < x) {
                if (less_head) {
                    less_cur->next = cur;
                    less_cur = cur;
                } else {
                    less_head = less_cur = cur;
                }
                less_cur->next = nullptr;
            } else {
                if (greater_head) {
                    greater_cur->next = cur;
                    greater_cur = cur;
                } else {
                    greater_head = greater_cur = cur;
                }
                greater_cur->next = nullptr;
            }
            cur = next;
        }
        if (less_head) {
            if (greater_head) {
                less_cur->next = greater_head;
            }
            return less_head;
        } else if (greater_head) {
            return greater_head;
        } else {
            return nullptr;
        }
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1,3,2};
    std::vector<ListNode*> nodes(v.size());
    std::transform(std::begin(v), std::end(v), std::begin(nodes), [](const int &n) { return new ListNode(n); });
    for (int i = 0; i < v.size() - 1 ; i++) {
        nodes[i]->next = nodes[i+1];
    }

    ListNode* ret = s.partition(nodes[0], 3);

    while (ret != nullptr) {
        std::cout << ret->val << std::endl;
        ret = ret->next;
    }
    return 0;
}