// Time:  O(n)
// Space: O(h)

// tree dp with stack
class Solution {
public:
    int minimumFlips(TreeNode* root, bool result) {
        static const int INF = numeric_limits<int>::max();
        static unordered_map<int, function<int(int, int)>> OP = {
            {2, [](int x, int y) { return x | y; }},
            {3, [](int x, int y) { return x & y; }},
            {4, [](int x, int y) { return x ^ y; }},
            {5, [](int x, int y) { return x != -1 ? !x : !y; }},
        };

        const auto& iter_dfs = [&]() {
            using RET = unordered_map<int, int>;
            RET ret;
            vector<tuple<int, TreeNode *, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk;
            stk.emplace_back(1, root, nullptr, nullptr, &ret);
            while (!empty(stk)) {
                auto [step, node, ret1, ret2, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (!node) {
                        (*ret)[-1] = 0;  // null object pattern
                        continue;
                    }
                    if (node->left == node->right) {
                        (*ret)[true] = node->val ^ 1;
                        (*ret)[false] = node->val ^ 0;
                        continue;
                    }
                    auto ret1 = make_shared<RET>(), ret2 = make_shared<RET>();
                    stk.emplace_back(2, node, ret1, ret2, ret);
                    stk.emplace_back(1, node->right, nullptr, nullptr, ret2.get());
                    stk.emplace_back(1, node->left, nullptr, nullptr, ret1.get());
                } else if (step == 2) {
                    for (const auto& [k1, v1] : *ret1) {
                        for (const auto& [k2, v2] : *ret2) {
                            const int nk = OP[node->val](k1, k2);
                            (*ret)[nk] = min(ret->count(nk) ? (*ret)[nk] : INF, v1 + v2);
                        }
                    }
                }
            }
            return ret[result];
        };

        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(h)
// tree dp with recursion
class Solution2 {
public:
    int minimumFlips(TreeNode* root, bool result) {
        static const int INF = numeric_limits<int>::max();
        static unordered_map<int, function<int(int, int)>> OP = {
            {2, [](int x, int y) { return x | y; }},
            {3, [](int x, int y) { return x & y; }},
            {4, [](int x, int y) { return x ^ y; }},
            {5, [](int x, int y) { return x != -1 ? !x : !y; }},
        };

        function<unordered_map<int, int> (TreeNode*)> dfs = [&](TreeNode *node) {
            unordered_map<int, int> dp;
            if (!node) {
                dp[-1] = 0;  // null object pattern
                return dp;
            }
            if (node->left == node->right) {
                dp[true] = node->val ^ 1;
                dp[false] = node->val ^ 0;
                return dp;
            }
            const auto& left = dfs(node->left);
            const auto& right = dfs(node->right);
            for (const auto& [k1, v1] : left) {
                for (const auto& [k2, v2] : right) {
                    const int nk = OP[node->val](k1, k2);
                    dp[nk] = min(dp.count(nk) ? dp[nk] : INF, v1 + v2);
                }
            }
            return dp;
        };

        return dfs(root)[result];
    }
};
