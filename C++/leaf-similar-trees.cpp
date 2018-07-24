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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> s1{root1} , s2{root2};
        while (!s1.empty() && !s2.empty()) {
            if (dfs(s1) != dfs(s2)) {
                return false;
            }
        }
        return s1.empty() && s2.empty();
    }

private:
    int dfs(vector<TreeNode*>& s) {
        while (true) {
            const auto node = s.back(); s.pop_back();
            if (node->right) {
                s.emplace_back(node->right);
            }
            if (node->left) {
                s.emplace_back(node->left);
            }
            if (!node->left && !node->right) {
                return node->val;
            }
        }
    }
};
