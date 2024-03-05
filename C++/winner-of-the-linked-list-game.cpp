// Time:  O(n)
// Space: O(1)

// linked list
class Solution {
public:
    string gameResult(ListNode* head) {
        int cnt = 0;
        for (; head; head = head->next->next) {
            cnt += head->val == head->next->val ? 0 : head->val < head->next->val ? -1 : 1;
        }
        return cnt == 0 ? "Tie" : cnt < 0 ? "Odd" : "Even";
    }
};
