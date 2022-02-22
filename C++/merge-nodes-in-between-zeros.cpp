// Time:  O(n)
// Space: O(1)

// linked list
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        for (auto curr = head->next, zero = head; curr; curr = curr->next) {
            if (curr->val) {
                zero->val += curr->val;
            } else {
                zero->next = curr->next ? curr : nullptr;
                zero = curr;
            }
        }
        return head;
    }
};
