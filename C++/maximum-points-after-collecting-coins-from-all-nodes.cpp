// Time:  O(nlogr), r = max(coins)
// Space: O(n)

// dfs, bitmasks, pruning
class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        static const int NEG_INF = numeric_limits<int>::min();

        vector<vector<int>> adj(size(coins));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const int mx = *max_element(cbegin(coins), cend(coins));
        const int max_base = 1 << (mx != 0 ? __lg(mx) + 1 : 0);
        vector<int> lookup(size(coins));
        const function<int (int, int, int)> dfs = [&](int u, int p, int base) {
            if (base >= max_base) {
                return 0;
            }
            if (lookup[u] & base) {  // we prefer the first way to the second way, so the visited state cannot improve the current chosen ways
                return NEG_INF;
            }
            lookup[u] |= base;
            int total1 = (coins[u] / base) - k;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& r = dfs(v, u, base);
                if (r == NEG_INF) {
                    total1 = r;
                    break;
                }
                total1 += r;
            }
            if ((coins[u] / base) - k >= coins[u] / (base << 1)) {  // if (coins[u]//base)-k >= coins[u]//(base*2), the first way is always better
                return total1;
            }
            int total2 = coins[u] / (base << 1);
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& r = dfs(v, u, base << 1);
                if (r == NEG_INF) {
                    total2 = r;
                    break;
                }
                total2 += r;
            }
            return max(total1, total2);
        };

        return dfs(0, -1, 1);
    }
};

// Time:  O(nlogr), r = max(coins)
// Space: O(nlogr)
// tree dp, memoization
class Solution2 {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        vector<vector<int>> adj(size(coins));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const int mx =  *max_element(cbegin(coins), cend(coins));
        const int max_d = mx != 0 ? __lg(mx) + 1 : 0;
        vector<vector<int>> lookup(size(coins), vector<int>(max_d, -1));
        const function<int (int, int, int)> memoization = [&](int u, int p, int d) {
            if (d >= max_d) {
                return 0;
            }
            if (lookup[u][d] == -1) {
                int total1 = (coins[u] >> d) - k;
                for (const auto& v : adj[u]) {
                    if (v != p) {
                        total1 += memoization(v, u, d);
                    }
                }
                int total2 = coins[u] >> (d + 1);
                for (const auto& v : adj[u]) {
                    if (v != p) {
                        total2 += memoization(v, u, d + 1);
                    }
                }
                lookup[u][d] = max(total1, total2);
            }
            return lookup[u][d];
        };

        return memoization(0, -1, 0);
    }
};
