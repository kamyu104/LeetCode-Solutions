// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        auto prev = head;
        int l = 2;
        while (prev->next) {
            auto curr = prev;
            int cnt = 0;
            for (; cnt < l && curr->next; ++cnt, curr = curr->next);
            ++l;
            if (cnt % 2) {
                prev = curr;
                continue;
            }
            curr = prev->next;
            ListNode *last = nullptr;
            while (cnt--) {
                auto nxt = curr->next;
                curr->next = last;
                last = curr;
                curr = nxt;
            }
            auto tail = prev->next;
            tail->next = curr;
            prev->next = last;
            prev = tail;
        }
        return head;
    }
};
