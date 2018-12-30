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
    bool isUnivalTree(TreeNode* root) {
        vector<TreeNode*> s{root};
        while (!s.empty()) {
            auto node = s.back(); s.pop_back();
            if (!node) {
                continue;
            }
            if (node->val != root->val) {
                return false;
            }
            s.emplace_back(node->left);
            s.emplace_back(node->right);
        }
        return true;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    bool isUnivalTree(TreeNode* root) {
        return (!root->left || (root->left->val == root->val & isUnivalTree(root->left))) &&
               (!root->right || (root->right->val == root->val & isUnivalTree(root->right)));
    }
};
