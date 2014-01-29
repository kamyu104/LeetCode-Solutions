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
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            ListNode dummy(-1);
            dummy.next = head;

            ListNode *prev = &dummy;

            for(int i = 0; i < m - 1; ++i) {
                prev = prev->next;
            }

            ListNode *const head2 = prev;

            prev = prev->next;
            ListNode *cur = prev->next;

            for(int i = m; i < n; ++i) {
                prev->next = cur->next;  // remove cur from the list
                cur->next = head2->next; // add cur to the head
                head2->next = cur;       // add cur to the head
                cur = prev->next;        // get next cur
            }

            return dummy.next;
        }
};
