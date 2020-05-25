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
    int pseudoPalindromicPaths (TreeNode* root) {
        int result = 0;
        vector<pair<TreeNode *, int>> stk = {{root, 0}};
        while (!stk.empty()) {
            auto [node, count] = stk.back(); stk.pop_back();
            if (!node) {
                continue;
            }
            count ^= 1 << node->val;
            result += int(!node->left && !node->right && (count & (count - 1)) == 0);
            stk.emplace_back(node->right, count);
            stk.emplace_back(node->left, count);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode *node, int count) {
        if (!node) {
            return 0;
        }
        count ^= 1 << node->val;
        return int(!node->left && !node->right && (count & (count - 1)) == 0) +
               dfs(node->left, count) + dfs(node->right, count);
    }
};
