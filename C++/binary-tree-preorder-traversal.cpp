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
        auto *curr = root;
        while (curr) {
            if (!curr->left) {
                res.emplace_back(curr->val);
                curr = curr->right;
            } else {
                auto *node = curr->left;
                while (node->right && node->right != curr) {
                    node = node->right;
                }
                if (!node->right) {
                    res.emplace_back(curr->val);
                    node->right = curr;
                    curr = curr->left;
                } else {
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return res; 
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode *, bool>> s;
        s.emplace(root, false);
        while (!s.empty()) {
            bool visited;
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
