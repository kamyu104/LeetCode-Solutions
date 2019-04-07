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
    int sumRootToLeaf(TreeNode* root) {
        return sumRootToLeafHelper(root, 0);
    }

private:
    int sumRootToLeafHelper(TreeNode* root, int val) {
        static const int M = 1e9 + 7;
        if (!root) {
            return 0;
        }
        val = (val * 2 + root->val) % M;
        if (!root->left && !root->right) {
            return val;
        }
        return (sumRootToLeafHelper(root->left, val) +
                sumRootToLeafHelper(root->right, val)) % M;
    }
};
