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

// dfs solution
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> level_sums;
        dfs(root, 0, &level_sums);
        return distance(level_sums.cbegin(),
                        max_element(level_sums.cbegin(), level_sums.cend())) + 1;
    }

private:
    void dfs(TreeNode *node, int i, vector<int> *level_sums) {
        if (!node) {
            return;
        }
        if (i == level_sums->size()) {
            level_sums->emplace_back();
        }
        (*level_sums)[i] += node->val;
        dfs(node->left, i + 1, level_sums);
        dfs(node->right, i + 1, level_sums);
    }
};

// Time:  O(n)
// Space: O(w)
// bfs solution
class Solution2 {
public:
    int maxLevelSum(TreeNode* root) {
        int result = 0, level = 1, max_total = numeric_limits<int>::min();
        queue<TreeNode*> q({root});
        while (!q.empty()) {
            queue<TreeNode*> next_q;
            int total = 0;
            while (!q.empty()) {
                const auto node = q.front(); q.pop();
                total += node->val;
                if (node->left) {
                    next_q.emplace(node->left);
                }
                if (node->right) {
                    next_q.emplace(node->right);
                }
            }
            if (total > max_total) {
                max_total = total;
                result = level;
            }
            q = move(next_q);
            ++level;
        }
        return result;
    }
};
