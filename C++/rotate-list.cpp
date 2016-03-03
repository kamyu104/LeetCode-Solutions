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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        // Get the length of the list.
        ListNode *cur = &dummy;
        int len = 0;
        while (cur->next) {
            ++len;
            cur = cur->next;
        }
        if (len == 0) {
            return nullptr;
        }

        k %= len;
        if (k == 0) {
            return head;
        }

        // Find the position to split.
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        while (k) {
            fast = fast->next;
            --k;
        }
        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        dummy.next = slow->next;  // New head.
        slow->next = nullptr;  // Split.
        fast->next = head;  // Link.

        return dummy.next;
    }
};
