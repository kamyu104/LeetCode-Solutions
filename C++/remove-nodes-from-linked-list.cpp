// Time:  O(n)
// Space: O(n)

// mono stack
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode *> stk;
        while (head) {
            while (!empty(stk) && stk.back()->val < head->val) {
                stk.pop_back();
            }
            if (!empty(stk)) {
                stk.back()->next = head;
            }
            stk.emplace_back(head);
            hea = head->next;
        }
        return stk[0];
    }
};
