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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int result = 0;
        vector<TreeNode*> s{root};
        while (!s.empty()) {
            auto node = s.back(); s.pop_back();
            if (node) {
                if (L <= node->val && node->val <= R) {
                    result += node->val;
                }
                if (L <= node->val) {
                    s.emplace_back(node->left);
                }
                if (node->val <= R) {
                    s.emplace_back(node->right);
                }
            }
        }
        return result;
    }
};
