// Time:  O(n)
// Space: O(n)

// iterative dfs, tree dp
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& iter_dfs = [&]() {
            int64_t result = 0;
            using RET = vector<int64_t>;
            RET ret = {price[0], 0};
            vector<tuple<int, int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, -1, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, p, i, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(2, u, p, 0, nullptr, ret);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    stk.emplace_back(2, u, p, i + 1, nullptr, ret);
                    const int v = adj[u][i];
                    if (v == p) {
                        continue;
                    }
                    const auto& new_ret = make_shared<RET>(vector<int64_t>{price[v], 0});  // [max_sum, max_sum_without_last_node]
                    stk.emplace_back(3, u, -1, -1, new_ret, ret);
                    stk.emplace_back(1, v, u, -1, nullptr, new_ret.get());
                } else if (step == 3) {
                    result = max({result, (*ret)[0] + (*new_ret)[1], (*ret)[1] + (*new_ret)[0]});
                    (*ret)[0] = max((*ret)[0], (*new_ret)[0] + price[u]);
                    (*ret)[1] = max((*ret)[1], (*new_ret)[1] + price[u]);
                }
            }
            return result;
        };
    
        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, tree dp
class Solution2 {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        int64_t result = 0;
        const function<vector<int64_t>(int, int)> dfs = [&](int u, int p) {
            vector<int64_t> dp = {price[u], 0};  // [max_sum, max_sum_without_last_node]
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& new_dp = dfs(v, u);
                result = max({result, dp[0] + new_dp[1], dp[1] + new_dp[0]});
                dp[0] = max(dp[0], new_dp[0] + price[u]);
                dp[1] = max(dp[1], new_dp[1] + price[u]);
            }
            return dp;
        };

        dfs(0, -1);
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// iterative dfs, tree dp
class Solution3 {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        
        const auto& iter_dfs = [&]() {
            vector<int64_t> dp(n);
            vector<tuple<int, int, int>> stk = {{1, 0, -1}};
            while (!empty(stk)) {
                const auto [step, u, p] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(2, u, p);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        stk.emplace_back(1, v, u);
                    }
                } else if (step == 2) {
                    dp[u] = price[u];
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        dp[u] = max(dp[u], dp[v] + price[u]);
                    }
                }
            }
            return dp;
        };

        const auto& dp = iter_dfs();
        const auto& iter_dfs2 = [&]() {
            int64_t result = 0;
            vector<tuple<int, int, int64_t>> stk = {{0, -1, 0}};
            while (!empty(stk)) {
                const auto [u, p, curr] = stk.back(); stk.pop_back();
                result = max({result, curr, dp[u] - price[u]});
                vector<vector<int64_t>> top2 = {{curr, p}, {0, -1}};
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    vector<int64_t> curr = {dp[v], v};
                    for (int i = 0; i < size(top2); ++i) {
                        if (curr > top2[i]) {
                            swap(top2[i], curr);
                        }
                    }
                }
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    stk.emplace_back(v, u, ((top2[0][1] != v) ? top2[0][0] : top2[1][0]) + price[u]);
                }
            }
            return result;
        };

        return iter_dfs2();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, tree dp
class Solution4_RE { // stack overflow due to deep recursion
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<int64_t> dp(n);
        const function<int64_t(int, int)> dfs = [&](int u, int p) {
            dp[u] = price[u];
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dp[u] = max(dp[u], dfs(v, u) + price[u]);
            }
            return dp[u];
        };

        int64_t result = 0;
        const function<void(int, int, int64_t)> dfs2 = [&](int u, int p, int64_t curr) {
            result = max({result, curr, dp[u] - price[u]});
            vector<vector<int64_t>> top2 = {{curr, p}, {0, -1}};
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                vector<int64_t> curr = {dp[v], v};
                for (int i = 0; i < size(top2); ++i) {
                    if (curr > top2[i]) {
                        swap(top2[i], curr);
                    }
                }
            }
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs2(v, u, ((top2[0][1] != v) ? top2[0][0] : top2[1][0]) + price[u]);
            }
        };

        dfs(0, -1);
        dfs2(0, -1, 0);
        return result;
    }
};
