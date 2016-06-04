// Time:  O(n^2)
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
        ListNode *insertionSortList(ListNode *head) {
        ListNode dummy{numeric_limits<int>::min()};

        auto curr = head;
        ListNode *position = nullptr;

        while (curr) {
            position = findInsertPosition(&dummy, curr->val);
            ListNode *tmp = curr->next;
            curr->next = position->next;
            position->next = curr;
            curr = tmp;
        }

        return dummy.next;
    }

    ListNode* findInsertPosition(ListNode *head, int x) {
        ListNode *prev = nullptr;
        for (auto curr = head; curr && curr->val <= x;
             prev = curr, curr = curr->next);
        return prev;
    }
};
