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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<int, vector<int>> neighbors;
        dfs(nullptr, root, &neighbors);

        vector<int> bfs{target->val};
        unordered_set<int> lookup{target->val};
        for (int i = 0; i < K; ++i) {
            vector<int> curr;
            for (const auto& node : bfs) {
                for (const auto& nei : neighbors[node]) {
                    if (!lookup.count(nei)) {
                        curr.emplace_back(nei);
                        lookup.emplace(nei);
                    }
                }
            }
            swap(bfs, curr);
        }
        return bfs;
    }

private:
    void dfs(TreeNode *parent, TreeNode *child,
             unordered_map<int, vector<int>> *neighbors) {
        if (!child) {
            return;
        }
        if (parent) {
            (*neighbors)[parent->val].emplace_back(child->val);
            (*neighbors)[child->val].emplace_back(parent->val);
        }
        dfs(child, child->left, neighbors);
        dfs(child, child->right, neighbors);
    }
};
