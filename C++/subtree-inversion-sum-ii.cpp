// Time:  O(n * k)
// Space: O(n + h * k)

// iterative dfs, tree dp
class Solution {
public:
    int subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        vector<vector<int>> adj(size(nums));
        const auto& iter_dfs = [&]() {
            using RET = vector<vector<int64_t>>;
            RET result{};
            vector<tuple<int, int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, -1, nullptr, &result}};
            while (!empty(stk)) {
                const auto [step, u, p, i, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    ret->assign(2, vector<int64_t>(k, nums[u]));
                    stk.emplace_back(4, -1, -1, -1, nullptr, ret);
                    stk.emplace_back(2, u, p, 0, nullptr, ret);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& v = adj[u][i];
                    stk.emplace_back(2, u, p, i + 1, nullptr, ret);
                    if (v == p) {
                        continue;
                    }
                    const auto& new_ret = make_shared<RET>();
                    stk.emplace_back(3, -1, -1, -1, new_ret, ret);
                    stk.emplace_back(1, v, u, -1, nullptr, new_ret.get());
                } else if (step == 3) {
                    auto& new_dp1 = (*new_ret)[0], &new_dp2 = (*new_ret)[1];
                    auto& dp1 = (*ret)[0], &dp2 = (*ret)[1];
                    for (int i = 0; i < k / 2; ++i) {
                        dp1[i] = max(dp1[i] + new_dp1[(k - 2) - i], dp1[(k - 2) - i] + new_dp1[i]);
                        dp2[i] = min(dp2[i] + new_dp2[(k - 2) - i], dp2[(k - 2) - i] + new_dp2[i]);
                    }
                    for (int i = k / 2; i < k; ++i) {
                        dp1[i] += new_dp1[i];
                        dp2[i] += new_dp2[i];
                    }
                    for (int i = k - 2; i >= 0; --i) {
                        dp1[i] = max(dp1[i], dp1[i + 1]);
                        dp2[i] = min(dp2[i], dp2[i + 1]);
                    }
                } else if (step == 4) {
                    auto& dp1 = (*ret)[0], &dp2 = (*ret)[1];
                    const auto mx = max(dp1[0], -dp2[k - 1]);
                    const auto mn = min(dp2[0], -dp1[k - 1]);
                    dp1.insert(begin(dp1), mx); dp1.pop_back();
                    dp2.insert(begin(dp2), mn); dp2.pop_back();
                }
            }
            return result[0][0];
        };
        
        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        return iter_dfs();
    }
};

// Time:  O(n * k)
// Space: O(n + h * k)
// dfs, tree dp
class Solution2 {
public:
    int subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        vector<vector<int>> adj(size(nums));
        const auto dfs = [&](this auto&& dfs, int u, int p) -> pair<vector<int64_t>, vector<int64_t>> {
            vector<int64_t> dp1(k, nums[u]), dp2(k, nums[u]);
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& [new_dp1, new_dp2] = dfs(v, u);
                for (int i = 0; i < k / 2; ++i) {
                    dp1[i] = max(dp1[i] + new_dp1[(k - 2) - i], dp1[(k - 2) - i] + new_dp1[i]);
                    dp2[i] = min(dp2[i] + new_dp2[(k - 2) - i], dp2[(k - 2) - i] + new_dp2[i]);
                }
                for (int i = k / 2; i < k; ++i) {
                    dp1[i] += new_dp1[i];
                    dp2[i] += new_dp2[i];
                }
                for (int i = k - 2; i >= 0; --i) {
                    dp1[i] = max(dp1[i], dp1[i + 1]);
                    dp2[i] = min(dp2[i], dp2[i + 1]);
                }
            }
            const auto mx = max(dp1[0], -dp2[k - 1]);
            const auto mn = min(dp2[0], -dp1[k - 1]);
            dp1.insert(begin(dp1), mx); dp1.pop_back();
            dp2.insert(begin(dp2), mn); dp2.pop_back();
            return pair(dp1, dp2);
        };
        
        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& [dp1, _] = dfs(0, -1);
        return dp1[0];
    }
};
