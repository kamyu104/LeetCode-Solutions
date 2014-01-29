// Time Complexity: O(n)
// Space Complexity: O(logn)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            return isValidBST(root, INT_MIN, INT_MAX);
        }

    private:
        bool isValidBST(TreeNode *root, int lower, int upper) {
            if(!root)
                return true;
            return root->val > lower && root->val < upper 
                && isValidBST(root->left, lower, root->val) 
                && isValidBST(root->right, root->val, upper);
        }
};
