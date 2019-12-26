#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // do nothing when 0 or 1 nodes
        if (!head || !head->next) {
            return head;
        }
        ListNode *ret = head->next;
        ListNode *before = nullptr;
        ListNode *cur = head;
        while (cur && cur->next) {
            std::cout << "swap " << cur->val << " " << cur->next->val << std::endl;
            swap(before, cur, cur->next, cur->next->next);
            before = cur;
            cur = cur->next;
        }
        return ret;
    }

    // swap 4 sequential nodes
    void swap(ListNode* before, ListNode *n1, ListNode *n2, ListNode *after) {
        n2->next = n1;
        if (before) {
            before->next = n2;
        }
        n1->next = after;
    }
};

int main() {
    Solution s;

    std::vector<int> v = {1, 2, 3, 4};
    std::vector<ListNode*> nodes(v.size());
    std::transform(v.begin(), v.end(), nodes.begin(), [](const int &n) { return new ListNode(n); });
    for (int i = 0 ; i < nodes.size() - 1 ; i++) {
        nodes[i]->next = nodes[i+1];
    }

    ListNode *ret = s.swapPairs(nodes[0]);

    while (ret != nullptr) {
        std::cout << ret->val << std::endl;
        ret = ret->next;
    }
    return 0;
}