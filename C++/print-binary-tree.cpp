// Time:  O(h * 2^h)
// Space: O(h * 2^h)

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
    vector<vector<string>> printTree(TreeNode* root) {
        auto h = getHeight(root), w = getWidth(root);
        vector<vector<string>> result(h, vector<string>(w, ""));
        preorderTraversal(root, 0, 0, w - 1, &result);
        return result;
    }

private:
    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    int getWidth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 2 * max(getWidth(root->left), getWidth(root->right)) + 1;
    }

    void preorderTraversal(TreeNode *root, int level, int left, int right, vector<vector<string>> *result) {
        if (!root) {
            return;
        }
        auto mid = left + (right - left) / 2;
        (*result)[level][mid] = to_string(root->val);
        preorderTraversal(root->left, level + 1, left, mid - 1, result);
        preorderTraversal(root->right, level + 1, mid + 1, right, result);
    }
};
