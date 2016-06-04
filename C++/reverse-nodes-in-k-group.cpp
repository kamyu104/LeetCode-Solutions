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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0};
        dummy.next = head;
        auto curr = head, curr_dummy = &dummy;
        int len = 0;

        while (curr) {
            auto next_curr = curr->next;
            len = (len + 1) % k;

            if (len == 0) {
                auto next_dummy = curr_dummy->next;
                reverse(&curr_dummy, curr->next);
                curr_dummy = next_dummy;
            }
            curr = next_curr;
        }
        return dummy.next;
    }

    void reverse(ListNode **begin, const ListNode *end) {
        ListNode *first = (*begin)->next;
        ListNode *curr = first->next;

        while (curr != end) {
            first->next = curr->next;
            curr->next = (*begin)->next;
            (*begin)->next = curr;
            curr = first->next;
        }
    }
};
