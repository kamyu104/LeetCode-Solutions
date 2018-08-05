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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, &diameter);
        return diameter;
    }

private:
    int depth(TreeNode *root, int *diameter) {
        if (!root) {
            return 0;
        }
        auto left = depth(root->left, diameter);
        auto right = depth(root->right, diameter);
        *diameter = max(*diameter, left + right);
        return 1 + max(left, right);
    }
};
