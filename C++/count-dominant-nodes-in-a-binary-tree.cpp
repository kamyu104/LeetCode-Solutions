// Time:  O(n)
// Space: O(h)

// iterative dfs
class Solution {
public:
    int countDominantNodes(TreeNode* root) {
        const auto& iter_dfs = [&]() {
            using RET = pair<int, int>;
            RET result{};
            vector<tuple<int, TreeNode *, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk = {{1, root, nullptr, nullptr, &result}};
            while (!empty(stk)) {
                const auto [step, u, ret1, ret2, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (!u) {
                        continue;
                    }
                    const auto& ret1 = make_shared<RET>();
                    const auto& ret2 = make_shared<RET>();
                    stk.emplace_back(2, u, ret1, ret2, ret);
                    stk.emplace_back(1, u->right, nullptr, nullptr, ret2.get());
                    stk.emplace_back(1, u->left, nullptr, nullptr, ret1.get());
                } else if (step == 2) {
                    const auto& mx = max({ret1->second, ret2->second, u->val});
                    *ret = pair(ret1->first + ret2->first + (mx == u->val ? 1 : 0), mx);
                }
            }
            return result.first;
        };

        return iter_dfs();
    }
};


// Time:  O(n)
// Space: O(h)
// dfs
class Solution2 {
public:
    int countDominantNodes(TreeNode* root) {
        const auto dfs = [](this auto&& dfs, auto u) -> pair<int, int> {
            if (!u) {
                return {0, 0};
            }
            const auto& [cnt1, mx1] = dfs(u->left);
            const auto& [cnt2, mx2] = dfs(u->right);
            const auto& mx = max({mx1, mx2, u->val});
            return {cnt1 + cnt2 + (mx == u->val ? 1 : 0), mx};
        };

        return dfs(root).first;
    }
};
