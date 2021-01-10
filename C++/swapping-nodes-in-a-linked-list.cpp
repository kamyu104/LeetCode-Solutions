// Time:  O(n)
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left = nullptr, *right = nullptr;
        for (auto curr = head; curr; curr = curr->next) {
            if (right) {
                right = right->next;
            }
            if (--k == 0) {
                left = curr;
                right = head;
            }
        }
        swap(left->val, right->val);
        return head;
    }
};
