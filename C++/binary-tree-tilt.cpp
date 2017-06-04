// Time:  O(n)
// Space: O(n)

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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        postOrderTraverse(root, &tilt);
        return tilt;
    }
private:
    int postOrderTraverse(TreeNode* root, int *tilt) {
        if (!root) {
            return 0;
        }
        auto left = postOrderTraverse(root->left, tilt);
        auto right = postOrderTraverse(root->right, tilt);
        *tilt += abs(left - right);
        return left + right + root->val;
    }
};
