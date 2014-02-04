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
        ListNode *rotateRight(ListNode *head, int k) {
            ListNode dummy(INT_MIN);
            dummy.next = head;
            ListNode *p = &dummy;
            for(int i = 0; p && i < k; ++i) {
                p = p->next;
                if(!p)
                    p = dummy.next;
            }

            if(!p || !p->next)
                return dummy.next;

            ListNode *cur = &dummy;
            for(; p->next; cur = cur->next, p = p->next); // find new head
            p->next = dummy.next;   // connect tail to the head
            dummy.next = cur->next; // update new head
            cur->next = NULL;       // update new tail

            return dummy.next;
        }
};
