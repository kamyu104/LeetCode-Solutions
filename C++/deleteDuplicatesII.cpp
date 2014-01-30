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
        ListNode *deleteDuplicates(ListNode *head) {
            if(!head)
                return NULL;
            ListNode dummy(INT_MIN);
            dummy.next = head;
            ListNode *pre2nd = &dummy;
            ListNode *pre1st = head;
            ListNode *cur = pre1st->next;
            bool isDup = false;

            while(pre1st) {
                if(cur && pre1st->val == cur->val) {
                    pre2nd->next = cur; // remove previous first node
                    delete pre1st;
                    pre1st = NULL;
                    isDup = true;
                }
                else if(isDup){
                    pre2nd->next = cur; // remove previous first node
                    delete pre1st;
                    pre1st = NULL;
                    isDup = false;
                }

                if(pre1st) pre2nd = pre1st;
                pre1st = cur;
                if(cur) cur = cur->next;
            }

            return dummy.next;
        }
};
