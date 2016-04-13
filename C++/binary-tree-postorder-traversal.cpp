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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode dummy(INT_MIN);
        dummy.left = root;
        auto *cur = &dummy;
        while (cur) {
            if (!cur->left) {
                cur = cur->right;
            } else {
                auto *node = cur->left;
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                if (!node->right) {
                    node->right = cur;
                    cur = cur->left;
                } else {
                    const auto& v = trace_back(cur->left, node);
                    res.insert(res.end(), v.cbegin(), v.cend());
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }

private:
    vector<int> trace_back(const TreeNode *from, const TreeNode *to) {
        vector<int> res;
        auto *cur = from;
        while (cur != to) {
            res.emplace_back(cur->val);
            cur = cur->right;
        }
        res.emplace_back(to->val);
        reverse(res.begin(), res.end());
        return res;
    }
};
