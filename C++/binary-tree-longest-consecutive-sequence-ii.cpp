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

    pair<int, int> longestConsecutiveHelper(TreeNode *root, int *max_len) {
        if (!root) {
            return {0, 0};
        }
        const pair<int, int> left_len = longestConsecutiveHelper(root->left, max_len);
        const pair<int, int> right_len = longestConsecutiveHelper(root->right, max_len);

        int cur_inc_len = 1, cur_dec_len = 1;
        if (root->left) {
            if (root->left->val == root->val + 1) {
                cur_inc_len = max(cur_inc_len, left_len.first + 1);
            } else if (root->left->val == root->val - 1){
                cur_dec_len = max(cur_dec_len, left_len.second + 1);
            }
        }
        if (root->right) {
            if (root->right->val == root->val + 1) {
                cur_inc_len = max(cur_inc_len, right_len.first + 1);
            } else if (root->right->val == root->val - 1) {
                cur_dec_len = max(cur_dec_len, right_len.second + 1);
            }
        }
        *max_len = max(*max_len, cur_dec_len + cur_inc_len - 1);
        return {cur_inc_len, cur_dec_len};
    }
};
