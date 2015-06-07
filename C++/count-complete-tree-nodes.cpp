// Time:  O(h * logn) = O((logn)^2)
// Space: O(1)

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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        TreeNode *node = root;
        int level = 0;
        while (node->left != nullptr) {
            node = node->left;
            ++level;
        }

        // Binary search.
        int left = pow(2, level), right = pow(2, level + 1);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (!exist(root, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }

    // Check if the nth node exist.
    bool exist(TreeNode *root, int n ) {
        int k = 1;
        while (k <= n) {
            k <<= 1;
        }
        k >>= 2;

        TreeNode *node = root;
        while (k > 0) {
            if ((n & k) == 0) {
                node = node->left;
            } else {
                node = node->right;
            }
            k >>= 1;
        }
        return node != nullptr;
    }
};
