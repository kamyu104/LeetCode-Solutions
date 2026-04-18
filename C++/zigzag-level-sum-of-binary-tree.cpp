// Time:  O(n)
// Space: O(w)

// bfs
class Solution {
public:
    vector<long long> zigzagLevelSum(TreeNode* root) {
        vector<long long> result;
        vector<TreeNode *> q = {root};
        for (int parity = 0; !empty(q); parity ^= 1) {
            vector<TreeNode *> new_q;
            int64_t total = 0;
            bool stop = false;
            for (int i = size(q) - 1; i >= 0; --i) {
                const auto& node = q[i];
                const auto& left = (parity == 0) ? node->left : node->right;
                const auto& right = (parity == 0) ? node->right : node->left;
                if (left) {
                    new_q.emplace_back(left);
                }
                if (right) {
                    new_q.emplace_back(right);
                }
                stop = stop || !left;
                if (!stop) {
                    total += node->val;
                }
            }
            result.emplace_back(total);
            q = move(new_q);
        }
        return result;
    }
};
