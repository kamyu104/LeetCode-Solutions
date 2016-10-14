// Time:  O(n)
// Space: O(logn)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto curr = head;
        int n = 0;
        while (curr) {
            curr = curr->next;
            ++n;
        }
        return BuildBSTFromSortedDoublyListHelper(&head, 0, n);
    }

    TreeNode * BuildBSTFromSortedDoublyListHelper(ListNode **head, int s, int e) {
        if (s == e) {
            return nullptr;
        }

        int m = s + ((e - s) / 2);
        auto left = BuildBSTFromSortedDoublyListHelper(head, s, m);
        auto curr = new TreeNode((*head)->val);

        *head = (*head)->next;
        curr->left = left;
        curr->right = BuildBSTFromSortedDoublyListHelper(head, m + 1, e);
        return curr;
    }
};
