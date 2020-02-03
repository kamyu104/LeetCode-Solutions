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
    int maxProduct(TreeNode* root) {
        static const int MOD = 1e9 + 7;
        int64_t result = 0;
        dfs(root, dfs(root, 0, &result), &result);
        return result % MOD;
    }

private:
    int64_t dfs(TreeNode *root, int64_t total, int64_t *result) {
        if (!root) {
            return 0;
        }
        int64_t subtotal = dfs(root->left, total, result) +
                           dfs(root->right, total, result) +
                           root->val;
        *result = max(*result, subtotal * (total - subtotal));
        return subtotal;
    }
};
