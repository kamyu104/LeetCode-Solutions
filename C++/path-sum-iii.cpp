// Time:  O(n^2)
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
    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        return pathSumHelper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int pathSumHelper(TreeNode* root, int prev, int sum) {
        if (!root) {
            return 0;
        }
        int curr = prev + root->val;
        return (curr == sum) + pathSumHelper(root->left, curr, sum) + pathSumHelper(root->right, curr, sum);
    }
};
