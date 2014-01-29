// Time Complexity: O(n^2)
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
        ListNode *insertionSortList(ListNode *head) {
            ListNode dummy(INT_MIN);

            ListNode *cur = head;
            ListNode *prev = NULL;
            ListNode *pos = head;

            while(cur) {
                pos = findInsertPos(&dummy, cur->val);
                ListNode *tmp = cur->next;
                cur->next = pos->next;
                pos->next = cur;
                cur = tmp;
            }

            return dummy.next;
        }

        ListNode* findInsertPos(ListNode *head, int x) {
            ListNode *pre = NULL;
            for (ListNode *cur = head; cur && cur->val <= x;
                    pre = cur, cur = cur->next);
            return pre;
        }
};
