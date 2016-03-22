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
    ListNode* reverseList(ListNode* head) {
        auto *dummy_head = new ListNode(0);

        while (head) {
            auto *tmp = head->next;
            head->next = dummy_head->next;
            dummy_head->next = head;
            head = tmp;
        }

        return dummy_head->next;
    }
};
