// Time Complexity: O(n * logk)
// Space Complexity: O(k)

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
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            return mergeKLists(lists, 0, lists.size() - 1);
        }
    private:
        ListNode *mergeKLists(vector<ListNode *> &lists, int begin, int end) {
            if(begin > end)
                return NULL;
            if(begin == end)
                return lists[begin];
            return mergeTwoLists(mergeKLists(lists, begin, (begin + end) / 2), mergeKLists(lists, (begin + end) / 2 + 1, end));
        }

        ListNode *mergeTwoLists(ListNode *left, ListNode *right) {
            ListNode dummy(INT_MIN);
            ListNode *p = &dummy;
            for(; left && right; p = p->next) {
                if(left->val < right->val) {
                    p->next = left;
                    left = left->next;
                }
                else {
                    p->next = right;
                    right = right->next;
                }
            }
            if(left) {
                p->next = left;
            }
            else {
                p->next = right;
            }

            return dummy.next;
        }
};
