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
        ListNode *left = head;
        while (left) {
            ListNode *right = left;
            while (right && left->val == right->val) { right = right->next; }
            left->next = right;
            left = right;
        }
        return head;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1,1,2,3,3};
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