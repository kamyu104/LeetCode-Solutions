// Time:  O(n)
// Space: O(h + d), d is the number of to_delete

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode *> result;
        unordered_set<int> to_delete_set(to_delete.cbegin(), to_delete.cend());
        delNodesHelper(to_delete_set, root, true, &result);
        return result;
    }

private:
    TreeNode *delNodesHelper(const unordered_set<int>& to_delete_set,
                             TreeNode *root,
                             bool is_root,
                             vector<TreeNode *> *result) {
        if (!root) {
            return nullptr;
        }
        bool is_deleted = to_delete_set.count(root->val) != 0;
        if (is_root && !is_deleted) {
            result->emplace_back(root);
        }
        root->left = delNodesHelper(to_delete_set, root->left, is_deleted, result);
        root->right = delNodesHelper(to_delete_set, root->right, is_deleted, result);
        return is_deleted ? nullptr : root;
    }
};
