// Time:  O(n)
// Space: O(h)

// bfs, quick select
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<int64_t> arr;
        vector<TreeNode *> q = {root};
        while (!empty(q)) {
            vector<TreeNode *> new_q;
            for (const auto& u : q) {
                if (u->left) {
                    new_q.emplace_back(u->left);
                }
                if (u->right) {
                    new_q.emplace_back(u->right);
                }
            }
            arr.emplace_back(accumulate(cbegin(q), cend(q), 0LL, [](const auto& total, const auto& node) {
                return total + node->val;
            }));
            q = move(new_q);
        }
        if (k - 1 >= size(arr)) {
            return -1;
        }
        nth_element(begin(arr), begin(arr) + (k - 1), end(arr), greater<int64_t>());
        return arr[k - 1];
    }
};
