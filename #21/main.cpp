#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto *p1 = l1;
        auto *p2 = l2;
        auto *dummy = new ListNode(0);
        auto *cur = dummy;
        while (p1 || p2) {
            if (p1 && p2) {
                // choose smaller one
                if (p1->val < p2->val) {
                    cur->next = p1;
                    p1 = p1->next;
                } else {
                    cur->next = p2;
                    p2 = p2->next;
                }
            } else if (p1) {
                cur->next = p1;
                p1 = p1->next;
            } else if (p2) {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};

int main() {

    Solution s;

    std::vector<int> v1 = {1, 2, 4};
    std::vector<int> v2 = {1, 3, 4};
    std::vector<ListNode*> nodes1(v1.size());
    std::vector<ListNode*> nodes2(v2.size());
    std::transform(v1.begin(), v1.end(), nodes1.begin(), [](const int &n) { return new ListNode(n); });
    std::transform(v2.begin(), v2.end(), nodes2.begin(), [](const int &n) { return new ListNode(n); });
    for (int i = 0 ; i < nodes1.size() - 1 ; i++) {
        nodes1[i]->next = nodes1[i+1];
    }
    for (int i = 0 ; i < nodes2.size() - 1 ; i++) {
        nodes2[i]->next = nodes2[i+1];
    }

    ListNode *ret = s.mergeTwoLists(nodes1[0], nodes2[0]);

    while (ret != nullptr) {
        std::cout << ret->val << std::endl;
        ret = ret->next;
    }
    return 0;
}