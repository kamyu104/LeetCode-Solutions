// Time:  O(n)
// Space: O(h)

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
    int longestConsecutive(TreeNode* root) {
        int max_len = 0;
        longestConsecutiveHelper(root, &max_len);
        return max_len;
    }

    int longestConsecutiveHelper(TreeNode *root, int *max_len) {
        if (!root) {
            return 0;
        }

        const int left_len = longestConsecutiveHelper(root->left, max_len);
        const int right_len = longestConsecutiveHelper(root->right, max_len);

        int cur_len = 1;
        if (root->left && root->left->val == root->val + 1) {
            cur_len = max(cur_len, left_len + 1);
        }
        if (root->right && root->right->val == root->val + 1) {
            cur_len = max(cur_len, right_len + 1);
        }
        *max_len = max(*max_len, max(cur_len, max(left_len, right_len)));
        return cur_len;
    }
};
