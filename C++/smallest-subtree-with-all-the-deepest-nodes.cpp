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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).node;
    }

private:
    struct Result {
        TreeNode *node;
        int depth;
    };

    Result dfs(TreeNode *node) {
        if (!node) {
            return {nullptr, 0};
        }
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        if (left.depth > right.depth) {
            return {left.node, left.depth + 1};
        }
        if (left.depth < right.depth) {
            return {right.node, right.depth + 1};
        }
        return {node, left.depth + 1};
    }
};
