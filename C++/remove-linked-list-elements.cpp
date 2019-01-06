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
    ListNode* removeElements(ListNode* head, int val) {
        for (auto** indirect = &head; *indirect != nullptr; ) {
            if ((*indirect)->val == val) {
                *indirect = (*indirect)->next;
                continue;
            }
            indirect = &((*indirect)->next) ; 
        }
        return head;
    }
};
