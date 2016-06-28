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
    ListNode* plusOne(ListNode* head) {
        auto rev_head = reverseList(head);

        auto curr = rev_head;
        int carry = 1;
        while (curr && carry) {
            curr->val += carry;
            carry = curr->val / 10;
            curr->val %= 10;
            if (carry && !curr->next) {
                curr->next = new ListNode(0);
            }
            curr = curr->next;
        }

        return reverseList(rev_head);
    }

private:
    ListNode* reverseList(ListNode* head) {
        auto dummy = ListNode{0};
        auto curr = head;

        while (curr) {
            auto tmp = curr->next;
            curr->next = dummy.next;
            dummy.next = curr;
            curr = tmp;
        }

        return dummy.next;
    }
};
