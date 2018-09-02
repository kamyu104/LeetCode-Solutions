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
    TreeNode* increasingBST(TreeNode* root) {
        return increasingBSTHelper(root, nullptr);
    }

private:
    TreeNode* increasingBSTHelper(TreeNode* root, TreeNode* tail) {
        if (!root) {
            return tail;
        }
        auto result = increasingBSTHelper(root->left, root);
        root->left = nullptr;
        root->right = increasingBSTHelper(root->right, tail);
        return result;
    }
};
