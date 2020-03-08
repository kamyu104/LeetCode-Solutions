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
    int maxSumBST(TreeNode* root) {
        int result = 0;
        dfs(root, &result);
        return result;
    }

private:
    tuple<bool, int, int, int> dfs(TreeNode *node, int *result) {
        if (!node) {
            return {true, 0,
                    numeric_limits<int>::max(),
                    numeric_limits<int>::min()};
        }
        const auto& [lvalid, lsum, lmin, lmax] = dfs(node->left, result);
        const auto& [rvalid, rsum, rmin, rmax] = dfs(node->right, result);
        if (lvalid && rvalid && lmax < node->val && node->val < rmin) {
            const auto& total = lsum + node->val + rsum;
            *result = max(*result, total);
            return {true, total, min(lmin, node->val), max(node->val, rmax)};
        }
        return {false, 0, 0, 0};
    }
};
