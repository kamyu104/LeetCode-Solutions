// Time:  O(n)
// Space: O(h)

class Solution {
public:
    int equalToDescendants(TreeNode* root) {
        return iter_dfs(root);
    }

private:
    int iter_dfs(TreeNode *node) {
        int result = 0;
        uint64_t total = 0;
        vector<tuple<int, TreeNode *, unique_ptr<uint64_t>, unique_ptr<uint64_t>, uint64_t*>> stk;
        stk.emplace_back(1, node, nullptr,  nullptr, &total);
        while (!empty(stk)) {
            const auto [step, node, ret1, ret2, ret] = move(stk.back()); stk.pop_back();
            if (step == 1) {
                if (!node) {
                    continue;
                }
                auto ret1 = make_unique<uint64_t>(), ret2 = make_unique<uint64_t>();
                auto p1 = ret1.get(), p2 = ret2.get();
                stk.emplace_back(2, node, move(ret1), move(ret2), ret);
                stk.emplace_back(1, node->right, nullptr, nullptr, p2);
                stk.emplace_back(1, node->left, nullptr, nullptr, p1);
            } else if (step == 2) {
                if (node->val == *ret1 + *ret2) {
                    ++result;
                }
                *ret = *ret1 + *ret2 + node->val;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(h)
class Solution2 {
public:
    int equalToDescendants(TreeNode* root) {
        int result = 0;
        dfs(root, &result);
        return result;
    }

private:
    uint64_t dfs(TreeNode *node, int *result) {
        if (!node) {
            return 0;
        }
        uint64_t total = dfs(node->left, result) + dfs(node->right, result);
        if (node->val == total) {
            ++(*result);
        }
        return total + node->val;
    }
};
