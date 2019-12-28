#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // do nothing for NULL ptr
        if (head == nullptr) {
            return head;
        }
        // sliding window to move to head
        ListNode *begin = head;
        ListNode *end = begin;

        // list length
        ListNode *cur = head;
        int len = 0;
        while (cur) {
            cur = cur->next;
            len++;
        }
        k = k % len;

        // no need to move
        if (k == 0) {
            return head;
        }

        for (int i = 0 ; i < k ; i++) {
            end = end->next;
        }

        while (end->next) {
            begin = begin->next;
            end = end->next;
        }

        ListNode *new_head = begin->next;
        end->next = head;
        begin->next = nullptr;
        return new_head;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1};
    std::vector<ListNode*> nodes(v.size());
    std::transform(std::begin(v), std::end(v), std::begin(nodes), [](const int &n) { return new ListNode(n); });
    for (int i = 0; i < v.size() - 1 ; i++) {
        nodes[i]->next = nodes[i+1];
    }

    ListNode* ret = s.rotateRight(nodes[0], 0);

    while (ret != nullptr) {
        std::cout << ret->val << std::endl;
        ret = ret->next;
    }
    return 0;
}