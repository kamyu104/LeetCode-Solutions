// Time:  O(n)
// Space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> result;
        vector<TreeNode *> stk = {root};
        while (!stk.empty()) {
            auto node = stk.back(); stk.pop_back();
            if (!node) {
                continue;
            }
            if (node->left && !node->right) {
                result.emplace_back(node->left->val);
            } else if (node->right && !node->left) {
                result.emplace_back(node->right->val);
            }
            stk.emplace_back(node->right);
            stk.emplace_back(node->left);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> result;
        dfs(root, &result);
        return result;
    }

private:
    void dfs(TreeNode *node, vector<int> *result) {
        if (!node) {
            return;
        }
        if (node->left && !node->right) {
            result->emplace_back(node->left->val);
        } else if (node->right && !node->left) {
            result->emplace_back(node->right->val);
        }
        dfs(node->left, result);
        dfs(node->right, result);
    }
};
