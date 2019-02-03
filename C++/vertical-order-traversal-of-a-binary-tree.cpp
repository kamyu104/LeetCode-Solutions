// Time:  O(nlogn)
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
    using Lookup = map<int, map<int, multiset<int>>>;

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        Lookup lookup;
        dfs(root, &lookup, 0, 0);
        vector<vector<int>> result;
        for (const auto& kvp1 : lookup) {
            vector<int> report;
            for (const auto& kvp2 : kvp1.second) {
                for (const auto& x : kvp2.second) {
                    report.emplace_back(x);
                }
            }
            result.emplace_back(move(report));
        }
        return result;
    }

private:
    void dfs(TreeNode *root, Lookup *lookup, int x, int y){
        if (!root) {
            return;
        }
        (*lookup)[x][y].emplace(root->val);
        dfs(root->left, lookup, x - 1, y + 1);
        dfs(root->right, lookup, x + 1, y + 1);
    }
};
