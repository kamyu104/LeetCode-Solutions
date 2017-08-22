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
        return dfs(root, 1, 0, &leftmosts);
    }

private:
    int dfs(TreeNode* node, int id, int depth, vector<int> *leftmosts) {
        if (!node) {
            return 0;
        }
        if (depth >= leftmosts->size()) {
            leftmosts->emplace_back(id);
        }
        int result = id - (*leftmosts)[depth] + 1;
        result = max(result, dfs(node->left, id * 2, depth + 1, leftmosts));
        result = max(result, dfs(node->right, id * 2 + 1, depth + 1, leftmosts));
        return result;
    }
};
