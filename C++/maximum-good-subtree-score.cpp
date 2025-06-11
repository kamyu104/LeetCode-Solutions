// Time:  O(n * (2^10)^2)
// Space: O(2^10)

// bitmasks, iterative dfs, tree dp
class Solution {
public:
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        static const int MOD = 1e9 + 7;

        vector<vector<int>> adj(size(vals));
        const auto& get_mask = [](int x) {
            int mask = 0;
            for (; x; x /= 10) {
                const int d = x % 10;
                if (mask & (1 << d)) {
                    return -1;
                }
                mask |= 1 << d;
            }
            return mask;
        };

        const auto& iter_dfs = [&]() {
            int result = 0;
            using RET = unordered_map<int, int>;
            RET ret;
            vector<tuple<int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, i, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    (*ret)[0] = 0;
                    const auto& mask = get_mask(vals[u]);
                    if (mask != -1) {
                        (*ret)[mask] = vals[u];
                    }
                    stk.emplace_back(4, u, -1, nullptr, ret);
                    stk.emplace_back(2, u, 0, nullptr, ret);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& v = adj[u][i];
                    stk.emplace_back(2, u, i + 1, nullptr, ret);
                    const auto& new_ret = make_shared<RET>();
                    stk.emplace_back(3, -1, -1, new_ret, ret);
                    stk.emplace_back(1, v, -1, nullptr, new_ret.get());
                } else if (step == 3) {
                    unordered_map<int, int> copy_dp(*ret);
                    for (const auto& [m1, v1] : copy_dp) {
                        for (const auto& [m2, v2] : *new_ret) {
                            if (m1 & m2) {
                                continue;
                            }
                            (*ret)[m1 | m2] = max((*ret)[m1 | m2], v1 + v2);
                        }
                    }
                } else if (step == 4) {
                    int mx = 0;
                    for (const auto& [_, v] : *ret) {
                        mx = max(mx, v);
                    }
                    result = (result + mx) % MOD;
                }
            }
            return result;
        };

        for (int u = 1; u < size(par); ++u) {
            adj[par[u]].emplace_back(u);
        }
        return iter_dfs();
    }
};

// Time:  O(n * (2^10)^2)
// Space: O(2^10)
// bitmasks, dfs, tree dp
class Solution2 {
public:
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        static const int MOD = 1e9 + 7;

        int result = 0;
        vector<vector<int>> adj(size(vals));
        const auto& get_mask = [](int x) {
            int mask = 0;
            for (; x; x /= 10) {
                const int d = x % 10;
                if (mask & (1 << d)) {
                    return -1;
                }
                mask |= 1 << d;
            }
            return mask;
        };

        const function<unordered_map<int, int> (int)> dfs = [&](int u) {
            unordered_map<int, int> dp;
            dp[0] = 0;
            const auto& mask = get_mask(vals[u]);
            if (mask != -1) {
                dp[mask] = vals[u];
            }
            for (const auto& v : adj[u]) {
                const auto& new_dp = dfs(v);
                unordered_map<int, int> copy_dp(dp);
                for (const auto& [m1, v1] : copy_dp) {
                    for (const auto& [m2, v2] : new_dp) {
                        if (m1 & m2) {
                            continue;
                        }
                        dp[m1 | m2] = max(dp[m1 | m2], v1 + v2);
                    }
                }
            }
            int mx = 0;
            for (const auto& [_, v] : dp) {
                mx = max(mx, v);
            }
            result = (result + mx) % MOD;
            return dp;
        };

        for (int u = 1; u < size(par); ++u) {
            adj[par[u]].emplace_back(u);
        }
        dfs(0);
        return result;
    }
};
