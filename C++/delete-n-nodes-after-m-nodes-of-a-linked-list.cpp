// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode dummy;
        dummy.next = head;
        head = &dummy;
        while (head) {
            for (int i = 0; i < m; ++i) {
                if (!head->next) {
                    return dummy.next;
                }
                head = head->next;
            }
            auto prev = head;
            for (int i = 0; i < n; ++i) {
                if (!head->next) {
                    prev->next = nullptr;
                    return dummy.next;
                }
                head = head->next;
            }
            prev->next = head->next;
        }
        return dummy.next;
    }
};
