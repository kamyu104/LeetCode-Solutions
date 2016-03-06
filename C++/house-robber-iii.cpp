// Time:  O(n)
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
    int rob(TreeNode* root) {
        pair<int, int> res = robHelper(root);
        return max(res.first, res.second);
    }

private:
    pair<int, int> robHelper(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        auto left = robHelper(root->left);
        auto right = robHelper(root->right);
        return {root->val + left.second + right.second,
                max(left.first, left.second) + max(right.first, right.second)};
    }
};
