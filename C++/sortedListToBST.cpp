// Time Complexity: O(n)
// Space Complexity: O(logn)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            int len = 0;

            ListNode *p = head;
            while(p) {
                p = p->next;
                ++len;
            }

            return sortedListToBST(head, len);
        }

    private:
        TreeNode *sortedListToBST(ListNode *&head, int len) {
            if(!len || !head)
                return NULL;
            TreeNode *left = sortedListToBST(head, len / 2);
            TreeNode *parent = new TreeNode(head->val);
            parent->left = left;
            head = head->next;
            parent->right = sortedListToBST(head, (len % 2 != 0)? len / 2: len / 2 - 1);
            return parent;
        }
};
