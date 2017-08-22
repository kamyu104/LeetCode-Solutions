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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> leftmosts;
        int result = 0;
        dfs(root, 1, 0, &leftmosts, &result);
        return result;
    }

private:
    void dfs(TreeNode* node, int id, int depth, vector<int> *leftmosts, int *result) {
        if (!node) {
            return;
        }
        if (depth >= leftmosts->size()) {
            leftmosts->emplace_back(id);
        }
        *result = max(*result, id - (*leftmosts)[depth] + 1);
        dfs(node->left, id * 2, depth + 1, leftmosts, result);
        dfs(node->right, id * 2 + 1, depth + 1, leftmosts, result);
    }
};
