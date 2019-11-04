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
    TreeNode* bstToGst(TreeNode* root) {
        int prev = 0;
        return bstToGstHelper(root, &prev);
    }

private:
    TreeNode* bstToGstHelper(TreeNode* root, int *prev) {
        if (!root) {
            return root;
        }
        bstToGstHelper(root->right, prev);
        root->val += *prev;
        *prev = root->val;
        bstToGstHelper(root->left, prev);
        return root;
    }
};
