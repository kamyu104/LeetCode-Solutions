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
    int findBottomLeftValue(TreeNode* root) {
        int result = 0, max_depth = 0;
        findBottomLeftValueHelper(root, 0, &max_depth, &result);
        return result;
    }

private:
    void findBottomLeftValueHelper(TreeNode *root, int curr_depth, int *max_depth, int *bottom_left_value) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right &&
            curr_depth + 1 > *max_depth) {
            *max_depth = curr_depth + 1;
            *bottom_left_value = root->val;
            return;
        }

        findBottomLeftValueHelper(root->left, curr_depth + 1, max_depth, bottom_left_value);
        findBottomLeftValueHelper(root->right, curr_depth + 1, max_depth, bottom_left_value);
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        q.emplace(root);
        TreeNode *node = nullptr;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node->right) {
                q.emplace(node->right);
            }
            if (node->left) {
                q.emplace(node->left);
            }
        }
        return node->val;
    }
};
