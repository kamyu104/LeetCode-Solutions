// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* frequenciesOfElements(ListNode* head) {
        ListNode dummy(0);
        auto curr = &dummy;
        for (int cnt = 0; head; head = head->next) {
            ++cnt;
            if (!head->next || head->next->val != head->val) {
                curr->next = new ListNode(cnt);
                curr = curr->next;
                cnt = 0;
            }
        }
        return dummy.next;
    }
};
