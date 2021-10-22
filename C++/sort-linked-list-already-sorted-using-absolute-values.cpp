// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode dummy;
        auto tail = &dummy, curr = head;
        while (curr) {
            auto nxt = curr->next;
            if (curr->val >= 0) {
                curr->next = nullptr;
                tail->next = curr;
                tail = curr;
            } else {
                if (tail == &dummy) {
                    tail = curr;
                }
                curr->next = dummy.next;
                dummy.next = curr;
            }
            curr = nxt;
        }
        return dummy.next;
    }
};


// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    ListNode* sortLinkedList(ListNode* head) {
        auto curr = head;
        head = nullptr;
        ListNode *tail = nullptr;
        while (curr) {
            auto nxt = curr->next;
            if (curr->val >= 0) {
                if (!head) {
                    head = curr;
                }
                curr->next = nullptr;
                if (tail) {
                    tail->next = curr;
                }
                tail = curr;
                
            } else {
                if (!tail) {
                    tail = curr;
                }
                curr->next = head;
                head = curr;
            }
            curr = nxt;
        }
        return head;
    }
};
