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
        ListNode *reverseKGroup(ListNode *head, int k) {
            ListNode dummy(INT_MIN);
            dummy.next = head;

            ListNode *cur = head;
            ListNode *cur_dummy = &dummy;
            int len = 0;

            while(cur) {
                ListNode *next = cur->next;
                len = (len + 1) % k;
                if(len == 0) {
                    ListNode *next_dummy = cur_dummy->next;
                    reverseKGroup(cur_dummy, cur->next);
                    cur_dummy = next_dummy;
                }
                cur = next;
            } 

            return dummy.next;
        }

        void reverseKGroup(ListNode *pre, ListNode *end) {
            ListNode *first = pre->next;
            ListNode *cur = first->next;
            while(cur != end) {
                ListNode *next = cur->next;
                first->next = cur->next;  // connect first node to the one next to current node
                cur->next = pre->next;    // remove current node from list and add the current node to the head
                pre->next = cur;          // connect previous node to the current node
                cur = next;               // set next node as current node
            }
        }
};
