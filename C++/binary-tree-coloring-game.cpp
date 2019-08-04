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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        pair<int, int> left_right;
        count(root, x, &left_right);
        const auto& [left, right] = left_right;
        const auto blue = max(max(left, right),
                              n - (left + right + 1));
        return blue > n - blue;
    }

private:
    int count(TreeNode *root, int x, pair<int, int> *left_right) {
        if (!root) {
            return 0;
        }
        const auto& left = count(root->left, x, left_right);
        const auto& right = count(root->right, x, left_right);
        if (root->val == x) {
            *left_right = make_pair(left, right);
        }
        return left + right + 1;
    }
};
