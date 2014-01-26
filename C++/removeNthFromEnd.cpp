// Time Complexity: O(n)
// Space Complexity: O(1)

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
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode *slow = head, *fast = head, *pre = NULL;

            while(n > 0) {
                fast = fast->next;
                --n;
            }

            while(fast) {
                pre = slow;
                slow = slow->next;
                fast = fast->next;
            }

            if(!pre && !slow->next)
                return NULL;

            if(!pre && slow->next)
                return slow->next;

            pre->next = slow->next;

            return head;
        }
};
