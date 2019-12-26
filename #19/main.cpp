#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        std::vector<ListNode*> nodes;
        while (1) {
            nodes.push_back(cur);
            if (cur->next == nullptr) {
                break;
            }
            cur = cur->next;
        }

        if (n > nodes.size()) {
            // do nothing
        } else if (n == nodes.size()) {
            head = head->next;
        } else if (n > 1) {
            nodes[nodes.size() - n - 1]->next = nodes[nodes.size() - n + 1];
        } else {
            nodes[nodes.size() - n - 1]->next = nullptr;
        }
        return head;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1, 2};
    std::vector<ListNode*> nodes(v.size());
    std::transform(v.begin(), v.end(), nodes.begin(), [](const int &n) { return new ListNode(n); });
    for (int i = 0 ; i < nodes.size() - 1 ; i++) {
        nodes[i]->next = nodes[i+1];
    }

    ListNode *cur = s.removeNthFromEnd(nodes[0], 2);
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;

    return 0;
}