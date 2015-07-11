// Time:  O(h)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto s = min(p->val, q->val);
        auto b = max(p->val, q->val);

        while (root->val < s || root->val > b) {
            // Keep searching since root is outside of [s, b].
            root = s <= root->val ? root->left : root->right;
        }

        // s <= root->val && root->val <= b.
        return root;   
    }
};
