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
            if(!root)
                return true;

            if(!isValidBST(root->left))
                return false;

            if(last && last != root && last->val >= root->val)
                return false;

            last = root;

            if(!isValidBST(root->right))
                return false;

            return true;
        }

    private:
        TreeNode *last;
};
