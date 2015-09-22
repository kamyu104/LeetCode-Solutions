// Time:  O(logn)
// Space: O(1)

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // If it has right subtree.
        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }

        // Search from root.
        TreeNode *successor = nullptr;
        while (root && root != p) { 
            if (root->val > p->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return successor;
    }
};
