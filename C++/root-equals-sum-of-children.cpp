// Time:  O(1)
// Space: O(1)

// tree
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};
