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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy{0};
        dummy.next = head;

        auto *prev = &dummy;

        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }

        auto *head2 = prev;

        prev = prev->next;
        auto *cur = prev->next;

        for (int i = m; i < n; ++i) {
            prev->next = cur->next;  // Remove cur from the list.
            cur->next = head2->next; // Add cur to the head.
            head2->next = cur;       // Add cur to the head.
            cur = prev->next;        // Get next cur.
        }

        return dummy.next;
    }
};
