// Time:  O(n)
// Space: O(n)

// iterative dfs, tree dp
class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        static const auto& NEG_INF = numeric_limits<int64_t>::min();
        static const auto& POS_INF = numeric_limits<int64_t>::max();

        vector<vector<int>> adj(n);
        vector<int64_t> dp(n);
        const auto iter_dfs = [&]() {
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
                    auto mx = NEG_INF, mn = POS_INF;
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        mx = max(mx, dp[v]);
                        mn = min(mn, dp[v]);
                    }
                    dp[u] = (mx != NEG_INF ? (2 * mx - mn) : 0) + baseTime[u];
                }
            }
        };

        const auto iter_dfs2 = [&]() -> int64_t {
            const auto top2 = [](int64_t a, int64_t b, int64_t x, auto cmp) -> pair<int64_t, int64_t> {
                if (cmp(x, a)) {
                    b = a;
                    a = x;
                } else if (cmp(x, b)) {
                    b = x;
                }
                return {a, b};
            };

            auto result = POS_INF;
            vector<tuple<int, int, int64_t>> stk = {{0, -1, NEG_INF}};
            while (!empty(stk)) {
                const auto [u, p, t] = stk.back(); stk.pop_back();
                auto mx1 = NEG_INF, mx2 = NEG_INF, mn1 = POS_INF, mn2 = POS_INF;
                for (const auto& v : adj[u]) {
                    const auto& x = (v != p) ? dp[v] : t;
                    tie(mx1, mx2) = top2(mx1, mx2, x, [](int64_t a, int64_t b) { return a > b; });
                    tie(mn1, mn2) = top2(mn1, mn2, x, [](int64_t a, int64_t b) { return a < b; });
                }
                result = min(result, (mx1 != NEG_INF ? (2 * mx1 - mn1) : 0) + baseTime[u]);
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    const auto& mx = (dp[v] != mx1) ? mx1 : mx2;
                    const auto& mn = (dp[v] != mn1) ? mn1 : mn2;
                    stk.emplace_back(v, u, (mx != NEG_INF ? (2 * mx - mn) : 0) + baseTime[u]);
                }
            }
            return result;
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        iter_dfs();
        return iter_dfs2();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, tree dp
class Solution2 {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        static const auto& NEG_INF = numeric_limits<int64_t>::min();
        static const auto& POS_INF = numeric_limits<int64_t>::max();

        vector<vector<int>> adj(n);
        vector<int64_t> dp(n);
        const auto dfs = [&](this auto&& dfs, int u, int p) -> void {
            auto mx = NEG_INF, mn = POS_INF;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
                mx = max(mx, dp[v]);
                mn = min(mn, dp[v]);
            }
            dp[u] = (mx != NEG_INF ? (2 * mx - mn) : 0) + baseTime[u];
        };

        auto result = POS_INF;
        const auto dfs2 = [&](this auto&& dfs2, int u, int p, int64_t t) -> void {
            const auto top2 = [](int64_t a, int64_t b, int64_t x, auto cmp) -> pair<int64_t, int64_t> {
                if (cmp(x, a)) {
                    b = a;
                    a = x;
                } else if (cmp(x, b)) {
                    b = x;
                }
                return {a, b};
            };

            auto mx1 = NEG_INF, mx2 = NEG_INF, mn1 = POS_INF, mn2 = POS_INF;
            for (const auto& v : adj[u]) {
                const auto& x = (v != p) ? dp[v] : t;
                tie(mx1, mx2) = top2(mx1, mx2, x, [](int64_t a, int64_t b) { return a > b; });
                tie(mn1, mn2) = top2(mn1, mn2, x, [](int64_t a, int64_t b) { return a < b; });
            }
            result = min(result, (mx1 != NEG_INF ? (2 * mx1 - mn1) : 0) + baseTime[u]);
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& mx = (dp[v] != mx1) ? mx1 : mx2;
                const auto& mn = (dp[v] != mn1) ? mn1 : mn2;
                dfs2(v, u, (mx != NEG_INF ? (2 * mx - mn) : 0) + baseTime[u]);
            }
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1, NEG_INF);
        return result;
    }
};
