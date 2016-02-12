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

        if (!root->left) {
            int size, min_val, max_val;
            tie(size, min_val, max_val) = largestBSTSubtreeHelper(root->right, max_size);
            if (size > 0 && root->val < min_val) {
                *max_size = max(*max_size, 1 + size);
                return make_tuple(1 + size, root->val, max_val);
            }
        } else if (!root->right) {
            int size, min_val, max_val;
            tie(size, min_val, max_val) = largestBSTSubtreeHelper(root->left, max_size);
            if (size > 0 && max_val < root->val) {
                *max_size = max(*max_size, 1 + size);
                return make_tuple(1 + size, min_val, root->val);
            }
        } else {
            int left_size, left_min, left_max, right_size, right_min, right_max;
            tie(left_size, left_min, left_max) = largestBSTSubtreeHelper(root->left, max_size);
            tie(right_size, right_min, right_max) = largestBSTSubtreeHelper(root->right, max_size);
            if (left_size > 0 && right_size > 0 &&
                left_max < root->val && root->val < right_min) {
                *max_size = max(*max_size, 1 + left_size + right_size);
                return make_tuple(1 + left_size + right_size, left_min, right_max);
            }
        }

        return make_tuple(0, root->val, root->val);
    }
};
