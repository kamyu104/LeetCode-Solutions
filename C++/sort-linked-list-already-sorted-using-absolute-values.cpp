// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode dummy;
        auto tail = &dummy;
        while (head) {
            auto nxt = head->next;
            if (head->val >= 0) {
                head->next = nullptr;
                tail->next = head;
                tail = head;
            } else {
                head->next = dummy.next;
                dummy.next = head;
                if (tail == &dummy) {
                    tail = head;
                }
            }
            head = nxt;
        }
        return dummy.next;
    }
};
