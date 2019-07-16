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
    double maximumAverageSubtree(TreeNode* root) {
        double result = 0.0;
        maximumAverageSubtreeHelper(root, &result);
        return result;
    }

private:
    pair<double, double> maximumAverageSubtreeHelper(TreeNode *root, double *result) {
        if (!root) {
            return {0, 0};
        }
        const auto& [s1, n1] = maximumAverageSubtreeHelper(root->left, result);
        const auto& [s2, n2] = maximumAverageSubtreeHelper(root->right, result);
        const auto& s = s1 + s2 + root->val;
        const auto& n = n1 + n2 + 1;
        *result = max(*result, s / n);
        return {s, n};
    }
};
