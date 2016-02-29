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
        ListNode dummy = ListNode(0);
        ListNode *cur = &dummy;
        int carry = 0;
        while (l1 || l2) {
            int val {carry};
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            carry = val / 10;
            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        return dummy.next;   
    }
};
