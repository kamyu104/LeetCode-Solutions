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
    int largestBSTSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int max_size = 1;
        largestBSTSubtreeHelper(root, &max_size);
        return max_size;
    }

private:
    tuple<int, int, int> largestBSTSubtreeHelper(TreeNode* root, int *max_size) {
        if (!root->left && !root->right) {
            return make_tuple(1, root->val, root->val);
        }

        int left_size = 0, left_min = root->val, left_max = root->val;
        if (root->left) {
            tie(left_size, left_min, left_max) = largestBSTSubtreeHelper(root->left, max_size);
        }

        int right_size = 0, right_min = root->val, right_max = root->val;
        if (root->right) {
            tie(right_size, right_min, right_max) = largestBSTSubtreeHelper(root->right, max_size);
        }

        int size = 0;
        if ((!root->left || left_size > 0) && 
            (!root->right || right_size > 0) &&
            left_max <= root->val && root->val <= right_min) {
            size = 1 + left_size + right_size;
            *max_size = max(*max_size, size);
        }

        return make_tuple(size, left_min, right_max);
    }
};
