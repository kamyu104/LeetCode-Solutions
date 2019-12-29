// Time:  O(n)
// Space: O(w)

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
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode *> curr = {root}, prev;
        while (!curr.empty()) {
            prev = move(curr);
            for (const auto& p : prev) {
                for (const auto& child : {p->left, p->right}) {
                    if (child) {
                        curr.emplace_back(child);
                    }
                }
            }
        }
        return accumulate(prev.cbegin(), prev.cend(), 0,
                          [](const auto& x, const auto& y) {
                              return x + y->val;
                          });
    }
};
