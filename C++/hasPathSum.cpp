// Time Complexity: O(n)
// Space Complexity: O(n)

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

        bool hasPathSum(TreeNode *root, int sum) {
            if(!root)
                return false;

            if(!root->left && !root->right)
                return sum == root->val;

            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        }
};
