// Time:  O(nlogn + qlogn)
// Space: O(nlogn)

// dfs, binary lifting
class Solution {
public:
    int distinctPaths(int n, vector<int>& parent, vector<vector<int>>& gates, vector<vector<int>>& queries) {
        static const int64_t MOD = 1e9 + 7;
        enum { BB, BR, RB, RR };
        using Mat = array<int64_t, 4>;

        const auto& ceil_log2 = [&](uint32_t x) {
            return bit_width(x - 1);
        };

        const auto& mult = [&](const auto& x, const auto& y) -> Mat {
            return {
                (x[BB] * y[BB] + x[BR] * y[RB]) % MOD,
                (x[BB] * y[BR] + x[BR] * y[RR]) % MOD,
                (x[RB] * y[BB] + x[RR] * y[RB]) % MOD,
                (x[RB] * y[BR] + x[RR] * y[RR]) % MOD,
            };
        };

        vector<int> depth(n);
        vector<vector<int>> par(ceil_log2(n - 1) + 1, vector<int>(n));
        const auto& lca = [&](int a, int b) {
            if (depth[a] < depth[b]) {
                swap(a, b);
            }
            const auto& d = depth[a] - depth[b];
            for (int k = 0; k < size(par); ++k) {
                if (d & (1 << k)) {
                    a = par[k][a];
                }
            }
            if (a == b) {
                return a;
            }
            for (int k = size(par) - 1; k >= 0; --k) {
                if (par[k][a] == par[k][b]) {
                    continue;
                }
                a = par[k][a];
                b = par[k][b];
            }
            return par[0][a];
        };

        vector<vector<Mat>> cnt(ceil_log2(n - 1) + 1, vector<Mat>(n));
        const auto& count = [&](int u, int card, int t) -> int64_t {
            if (u == t) {
                return 1;
            }
            const auto& d = depth[u] - depth[t];
            int64_t b = (card == 0) ? 1 : 0;
            int64_t r = (card == 1) ? 1 : 0;
            for (int k = 0; k < size(par); ++k) {
                if (!(d & (1 << k))) {
                    continue;
                }
                tie(b, r) = pair((b * cnt[k][u][BB] + r * cnt[k][u][RB]) % MOD, (b * cnt[k][u][BR] + r * cnt[k][u][RR]) % MOD);
                u = par[k][u];
            }
            return (b + r) % MOD;
        };

        vector<vector<int>> adj(n);
        for (int u = 0; u < n; ++u) {
            if (parent[u] != -1) {
                adj[parent[u]].emplace_back(u);
            }
        }
        vector<int> stk = {0};
        while (!empty(stk)) {
            const auto u = stk.back(); stk.pop_back();
            for (const auto& v : adj[u]) {
                depth[v] = depth[u] + 1;
                stk.emplace_back(v);
            }
        }
        for (int u = 0; u < n; ++u) {
            par[0][u] = parent[u];
            cnt[0][u] = {gates[u][1], gates[u][2], gates[u][2], gates[u][0]};
        }
        for (int k = 1; k < size(par); ++k) {
            for (int u = 0; u < n; ++u) {
                if (par[k - 1][u] == -1) {
                    continue;
                }
                par[k][u] = par[k - 1][par[k - 1][u]];
                cnt[k][u] = mult(cnt[k - 1][u], cnt[k - 1][par[k - 1][u]]);
            }
        }
        int result = 0;
        for (const auto& q : queries) {
            const auto& l = lca(q[0], q[2]);
            result ^= (count(q[0], q[1], l) * count(q[2], q[3], l)) % MOD;
        }
        return result;
    }
};
