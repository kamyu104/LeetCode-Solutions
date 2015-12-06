// Time:  O(n)
// Space: O(n)

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> cols;
        vector<pair<TreeNode *, int>> queue{{root, 0}};
        for (int i = 0; i < queue.size(); ++i) {
            TreeNode *node;
            int j;
            tie(node, j) = queue[i];
            if (node) {
                cols[j].emplace_back(node->val);
                queue.push_back({node->left, j - 1});
                queue.push_back({node->right, j + 1});
            }
        }
        int min_idx = numeric_limits<int>::max(), 
            max_idx = numeric_limits<int>::min();
        for (const auto& kvp : cols) {
            min_idx = min(min_idx, kvp.first);
            max_idx = max(max_idx, kvp.first);
        }
        vector<vector<int>> res;
        for (int i = min_idx; !cols.empty() && i <= max_idx; ++i) {
            res.emplace_back(move(cols[i]));
        }
        return res;
    }
};
