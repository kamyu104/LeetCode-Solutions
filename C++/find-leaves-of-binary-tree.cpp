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
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        findLeavesHelper(root, &result);
        return result;
    }

private:
    int findLeavesHelper(TreeNode *node, vector<vector<int>> *result) {
        if (node == nullptr) {
            return -1;
        }
        const int level = 1 + max(findLeavesHelper(node->left, result),
                                  findLeavesHelper(node->right, result));
        if (result->size() < level + 1){
            result->emplace_back();
        }
        (*result)[level].emplace_back(node->val);
        return level;
    }
};
