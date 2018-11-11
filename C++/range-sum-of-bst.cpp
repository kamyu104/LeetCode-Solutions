// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        return (root == nullptr) ? 
            0 : (root->val >= L && root->val <= R) * root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }   
};