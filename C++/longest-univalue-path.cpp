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
    int longestUnivaluePath(TreeNode* root) {
        auto result = 0;
        dfs(root, &result);
        return result;
    }

private:
    int dfs(TreeNode *node, int *result) {
        if (!node) {
            return 0;
        }
        auto left = dfs(node->left, result);
        auto right = dfs(node->right, result);
        left = node->left && node->val == node->left->val ? left + 1 : 0;
        right = node->right && node->val == node->right->val ? right + 1 : 0;
        *result = max(*result, left + right);
        return max(left, right);
    }
};
