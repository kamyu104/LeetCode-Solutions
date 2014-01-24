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
    int maxDepth(TreeNode *root) {
        if(!root)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if(left > right) return left + 1;
        else return right + 1;
    }
};
