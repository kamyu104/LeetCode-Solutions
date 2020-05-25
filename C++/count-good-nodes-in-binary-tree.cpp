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
    int goodNodes(TreeNode* root) {
        int result = 0;
        vector<pair<TreeNode *, int>> stk = {{root, root->val}};
        while (!stk.empty()) {
            auto [node, curr_max] = stk.back(); stk.pop_back();
            if (!node) {
                continue;
            }
            curr_max = max(curr_max, node->val);
            result += (curr_max <= node->val);
            stk.emplace_back(node->right, curr_max);
            stk.emplace_back(node->left, curr_max);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode *node, int curr_max) {
        if (!node) {
            return 0;
        }
        curr_max = max(curr_max, node->val);
        return (curr_max <= node->val) +
               dfs(node->left, curr_max) + dfs(node->right, curr_max);
    }
};
