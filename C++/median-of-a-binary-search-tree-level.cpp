// Time:  O(n)
// Space: O(n)

// bfs
class Solution {
public:
    int levelMedian(TreeNode* root, int level) {
        const auto& bfs = [](auto root, int level) {
            vector<TreeNode *> q = {root};
            for (int d = 0; !empty(q); ++d) {
                if (d == level) {
                    return q;
                }
                vector<TreeNode *> new_q;
                for (const auto& u : q) {
                    if (u->left) {
                        new_q.emplace_back(u->left);
                    }
                    if (u->right) {
                        new_q.emplace_back(u->right);
                    }
                }
                q = move(new_q);
            }
            return vector<TreeNode *>();
        };

        const auto& arr = bfs(root, level);
        return !empty(arr) ? arr[size(arr) / 2]->val : -1;
    }
};
