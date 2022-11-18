// Time:  O(nlogn)
// Space: O(w)

// bfs, sort
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int result = 0;
        vector<TreeNode *> q = {root};
        while (!empty(q)) {
            vector<TreeNode *> new_q;
            for (const auto& node : q) {
                if (node->left) {
                    new_q.emplace_back(node->left);
                }
                if (node->right) {
                    new_q.emplace_back(node->right);
                }
            }
            vector<int> idx(size(q));
            iota(begin(idx), end(idx), 0);
            sort(begin(idx), end(idx), [&](int a, int b) { return q[a]->val < q[b]->val; });
            for (int i = 0; i < size(idx); ++i) {
                for (; idx[i] != i; swap(idx[idx[i]], idx[i]), ++result);
            }
            q = move(new_q);
        }
        return result;
    }
};
