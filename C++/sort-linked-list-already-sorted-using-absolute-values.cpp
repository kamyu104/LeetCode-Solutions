// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        auto tail = head;
        auto curr = head->next;
        head->next = nullptr;
        while (curr) {
            auto nxt = curr->next;
            if (curr->val > 0) {
                curr->next = nullptr;
                tail->next = curr;
                tail = curr;
                
            } else {
                curr->next = head;
                head = curr;
            }
            curr = nxt;
        }
        return head;
    }
};
