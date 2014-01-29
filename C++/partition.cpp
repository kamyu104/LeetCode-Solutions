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
        ListNode *partition(ListNode *head, int x) {
            ListNode left_dummy(-1);
            ListNode right_dummy(-1);
            auto left_cur = &left_dummy;
            auto right_cur = &right_dummy;

            for(auto cur = head; cur; cur = cur->next) {
                if(cur->val < x) {
                    left_cur->next = cur;
                    left_cur = cur;
                }
                else {
                    right_cur->next = cur;
                    right_cur = cur;
                }
            }

            left_cur->next = right_dummy.next;
            right_cur->next = nullptr;
            return left_dummy.next;
        }
};
