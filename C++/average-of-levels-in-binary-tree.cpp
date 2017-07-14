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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            int64_t sum = 0, count = 0;
            queue<TreeNode *> next;
            while (!q.empty()) {
                auto n = q.front();
                q.pop();
                sum += n->val;
                ++count;
                if (n->left) {
                    next.emplace(n->left);
                }
                if (n->right) {
                    next.emplace(n->right);
                }
            }
            swap(q, next);
            result.emplace_back(sum * 1.0 / count);
        }
        return result;
    }
};

