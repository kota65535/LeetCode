#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        // dummy node. the value must be different to head
        ListNode *dummy = new ListNode(head->val ^ 1);
        dummy->next = head;
        ListNode *left = dummy, *mid = head, *right = head;
        while (right) {
            // move forward right pointer until different value appears
            while (right && mid->val == right->val) { right = right->next; }
            if (mid->next != right) {
                // skip duplicate nodes
                left->next = right;
            } else {
                // no duplicate node, move forward left pointer
                left = mid;
            }
            // reset mid pointer
            mid = right;
        }
        return dummy->next;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {-2147483648,2147483647,2};
    std::vector<ListNode*> nodes(v.size());
    std::transform(std::begin(v), std::end(v), std::begin(nodes), [](const int &n) { return new ListNode(n); });
    for (int i = 0; i < v.size() - 1 ; i++) {
        nodes[i]->next = nodes[i+1];
    }

    ListNode* ret = s.deleteDuplicates(nodes[0]);

    while (ret != nullptr) {
        std::cout << ret->val << std::endl;
        ret = ret->next;
    }
    return 0;
}
