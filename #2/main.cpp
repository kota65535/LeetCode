#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *pl1 = l1, *pl2 = l2;
        while (true) {
            carry = processCurrentNode(pl1, pl2, carry);
            if (carry) {
                if (!pl1->next && pl2->next) {
                    pl1->next = new ListNode(0);
                }
                if (pl1->next && !pl2->next) {
                    pl2->next = new ListNode(0);
                }
                if (! pl1->next && ! pl2->next) {
                    pl1->next = new ListNode(1);
                    break;
                }
            } else {
                if (! pl1->next && pl2->next) {
                    pl1->next = pl2->next;
                    break;
                }
                if (pl1->next && ! pl2->next) {
                    break;
                }
                if (! pl1->next && ! pl2->next) {
                    break;
                }
            }
            pl1 = pl1->next;
            pl2 = pl2->next;
        }
        return l1;
    }

    int processCurrentNode(ListNode *l1, ListNode *l2, int carry) {
        l1->val += l2->val + carry;
        carry = l1->val / 10;
        l1->val %= 10;
        return carry;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}