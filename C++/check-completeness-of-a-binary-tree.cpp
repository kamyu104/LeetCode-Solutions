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
    bool isCompleteTree(TreeNode* root) {
        bool end = false;
        vector<TreeNode*> current{root};
        while (current.empty() == false) {
            vector<TreeNode*> next_level;
            for (const auto& node : current) {
                if (!node) {
                    end = true;
                    continue;
                }
                if (end) {
                    return false;
                }
                next_level.emplace_back(node->left);
                next_level.emplace_back(node->right);
            }
            current = move(next_level);
        }
        return true;
    }
};

// Time:  O(n)
// Space: O(w)
class Solution2 {
public:
    bool isCompleteTree(TreeNode* root) {
        vector<pair<TreeNode*, int>> prev_level, current{{root, 1}};
        int count = 0;
        while (current.empty() == false) {
            count += current.size();
            vector<pair<TreeNode*, int>> next_level;
            for (const auto& node : current) {
                if (node.first) {
                    next_level.emplace_back(node.first->left, 2 * node.second);
                    next_level.emplace_back(node.first->right, 2 * node.second + 1);
                }
            }
            prev_level = move(current);
            current = move(next_level);
        }
        return prev_level.back().second == count;
    }
};
