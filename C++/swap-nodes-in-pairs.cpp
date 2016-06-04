// Time:  O(n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy{0};
        dummy.next = head;
        auto curr = &dummy;
        while (curr->next && curr->next->next) {
            auto next_one = curr->next;
            auto next_two = next_one->next;
            auto next_three = next_two->next;
            curr->next = next_two;
            next_two->next = next_one;
            next_one->next = next_three;
            curr = next_one;
        }
        return dummy.next; 
    }
};
