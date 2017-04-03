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
    TreeNode* convertBST(TreeNode* root) {
        int cur_sum = 0;
        convertBSTHelper(root, &cur_sum);
        return root;
    }

private:
    void convertBSTHelper(TreeNode* root, int *cur_sum) {
        if (!root) {
            return;
        }

        if (root->right) {
            convertBSTHelper(root->right, cur_sum);
        }
        root->val = (*cur_sum += root->val);
        if (root->left) {
            convertBSTHelper(root->left, cur_sum);
        }
    }
};
