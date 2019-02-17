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
    bool isCousins(TreeNode* root, int x, int y) {
        int depth_x = 0, depth_y = 0;
        TreeNode *parent_x = nullptr, *parent_y = nullptr;
        return dfs(root, x, &depth_x, &parent_x) &&
               dfs(root, y, &depth_y, &parent_y) &&
               depth_x == depth_y &&
               parent_x != parent_y;
    }
    
private:
    bool dfs(TreeNode *root, int x, int *depth, TreeNode **parent) {
        if (!root) {
            return false;
        }
        if (root->val == x) {
            return true;
        }
        ++(*depth);
        auto prev_parent = (*parent);
        (*parent) = root;
        if (dfs(root->left, x, depth, parent)) {
            return true;
        }
        (*parent) = root;
        if (dfs(root->right, x, depth, parent)) {
            return true;
        }
        (*parent) = prev_parent;
        --(*depth);
        return false;
    }
};
