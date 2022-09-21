// Time:  O(n)
// Space: O(n)

// bfs
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> q = {root};
        for (int parity = 0; !empty(q); parity ^= 1) {
            if (parity) {
                for (int left = 0, right = size(q) - 1; left < right; ++left, --right) {
                    swap(q[left]->val, q[right]->val);
                }
            }
            if (!q[0]->left) {
                break;
            }
            vector<TreeNode*> new_q;
            for (const auto& node : q) {
                new_q.emplace_back(node->left);
                new_q.emplace_back(node->right);
            }
            q = move(new_q);
        }
        return root;
    }
};
