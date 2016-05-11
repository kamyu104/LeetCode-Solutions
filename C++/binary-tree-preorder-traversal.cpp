// Time:  O(n)
// Space: O(1)

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *prev = nullptr;
        auto *cur = root;
        while (cur) {
            if (!cur->left) {
                res.emplace_back(cur->val);
                prev = cur;
                cur = cur->right;
            } else {
                auto *node = cur->left;
                while (node->right && node->right != cur) {
                    node = node->right;
                }
                if (!node->right) {
                    res.emplace_back(cur->val);
                    prev = cur;
                    node->right = cur;
                    cur = cur->left;
                } else {
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res; 
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode *, bool>> s;
        s.emplace(root, false);
        bool visited;
        while (!s.empty()) {
            tie(root, visited) = s.top();
            s.pop();
            if (root == nullptr) {
                continue;
            }
            if (visited) {
                res.emplace_back(root->val);
            } else {
                s.emplace(root->right, false);
                s.emplace(root->left, false);
                s.emplace(root, true);
            }
        }
        return res;
    }
};
