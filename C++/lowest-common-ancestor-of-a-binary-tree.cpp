// Time:  O(h)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
         // 1. If the current subtree contains both p and q,
         //    return their LCA.
         // 2. If only one of them is in that subtree,
         //    return that one of them.
         // 3. If neither of them is in that subtree,
         //    return the node of that subtree.
        return left ? (right ? root : left) : right;
    }
};
