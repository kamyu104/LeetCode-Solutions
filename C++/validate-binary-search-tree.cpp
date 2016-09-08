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
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        if (!isValidBST(root->left)) {
            return false;
        }

        if (last && last != root && last->val >= root->val) {
            return false;
        }

        last = root;

        if (!isValidBST(root->right)) {
            return false;
        }

        return true;
    }

private:
    TreeNode *last = nullptr;
};
