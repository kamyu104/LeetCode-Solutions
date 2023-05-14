// Time:  O(n)
// Space: O(1)

// two pointers, slow and fast pointers
class Solution {
public:
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        auto head1 = list;
        auto slow = head1, fast = head1->next;
        while (fast->next != head1) {
            slow = slow->next,
            fast = fast->next->next != head1 ? fast->next->next : fast->next;
        }
        auto head2 = slow->next;
        slow->next = head1;
        fast->next = head2;
        return {head1, head2};
    }
};
