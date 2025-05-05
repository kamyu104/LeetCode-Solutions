// Time:  O(n + qlogm)
// Space: O(n)

// bfs, fast exponentiation
class Solution {
public:
    vector<int> queryConversions(vector<vector<int>>& conversions, vector<vector<int>>& queries) {
        static const int MOD = 1e9 + 7;

        const auto& powmod = [&](int a, int b) {
            a %= MOD;
            int64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = result * a % MOD;
                }
                a = int64_t(a) * a % MOD;
                b >>= 1;
            }
            return result;
        };

        const auto& divmod = [&](int a, int b) {
            return (a * powmod(b, MOD - 2)) % MOD;
        };

        const auto& unit = [&]() {
            vector<vector<pair<int, int>>> adj(size(conversions) + 1);
            for (const auto& c : conversions) {
                adj[c[0]].emplace_back(c[1], c[2]);
            }
            vector<int> result(size(adj));
            result[0] = 1;
            vector<int> q = {0};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& [v, w] : adj[u]) {
                        result[v] = (static_cast<int64_t>(result[u]) * w) % MOD;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return result;
        };

        const auto& lookup = unit();
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            result[i] = divmod(lookup[queries[i][1]], lookup[queries[i][0]]);
        }
        return result;
    }
};
