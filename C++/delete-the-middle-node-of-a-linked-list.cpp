// Time:  O(n)
// Space: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        auto slow = &dummy, fast = &dummy; 
        while (fast->next && fast->next->next) {  
            slow = slow->next; 
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return dummy.next; 
    }
};

// Time:  O(n)
// Space: O(1)
class Solution {
public:
    ListNode *deleteMiddle(ListNode *head) {
        ListNode **node = &head, *fast = head;
        for (ListNode *fast = head; fast && fast->next; fast = fast->next->next)
            node = &(*node)->next;
        *node = (*node)->next;
        return head;
    }
};