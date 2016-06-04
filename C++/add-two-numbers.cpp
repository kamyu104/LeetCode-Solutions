// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto curr = &dummy;

        auto carry = 0;
        while (l1 || l2 || carry) {
            auto a = l1? l1->val : 0, b = l2? l2->val : 0;
            auto val = carry + a + b;
            curr->next = new ListNode(val % 10);
            carry = val / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            curr = curr->next;
        }

        return dummy.next;
    }
};
