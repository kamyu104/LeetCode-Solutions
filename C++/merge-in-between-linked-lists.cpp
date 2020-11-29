// Time:  O(m + n)
// Space: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev_first = nullptr, *last = list1;
        for (int i = 0; i < b; ++i) {
            if (i == a - 1) {
                prev_first = last;
            }
            last = last->next;
        }
        prev_first->next = list2;
        for (; list2->next; list2 = list2->next);
        list2->next = last->next;
        last->next = nullptr;
        return list1;
    }
};
