// Time:  O(n^2 * 2^n)
// Space: O(n * 2^n)

// combination based dp
class Solution {
public:
    int maximumCost(int n, vector<vector<int>>& highways, int k) {
        if (k + 1 > n) {  // optionally optimize
            return -1;
        }
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& h : highways) {
            adj[h[0]].emplace_back(h[1], h[2]);
            adj[h[1]].emplace_back(h[0], h[2]);
        }
        vector<pair<int, vector<int>>> dp(1 << n);
        for (int u = 0; u < n; ++u) {
            dp[1 << u].second.emplace_back(u);
        }
        int result = k != 1 ? -1 : 0;
        for (int cnt = 1; cnt <= n; ++cnt) {
            combinations(n, cnt, 
                         [&k, &adj, &dp, &result](const vector<int>& idxs) {
                             auto mask = accumulate(cbegin(idxs), cend(idxs), 0,
                                                    [](const auto& a, const auto& b) {
                                                        return a | (1 << b);
                                                    });
                             const auto& [total, lasts] = dp[mask];
                             for (const auto& u : lasts) {
                                 for (const auto& [v, t] : adj[u]) {
                                     if (mask & (1 << v)) {
                                         continue;
                                     }
                                     int new_mask = mask | (1 << v);
                                     if (total + t < dp[new_mask].first) {
                                         continue;
                                     }
                                     if (total + t == dp[new_mask].first) {
                                         dp[new_mask].second.emplace_back(v);
                                         continue;
                                     }
                                     dp[new_mask].first = total + t;
                                     dp[new_mask].second = {v};
                                     if (__builtin_popcount(mask) == k) {
                                         result = max(result, dp[new_mask].first);
                                     }
                                 }
                             }
                         });
        }
        return result;
    }

private:
    void combinations(int n, int k, const function<void (const vector<int>&)>& callback) {
        static const auto& next_pos =
            [](const auto& n, const auto& k, const auto& idxs) {
                int i = k - 1;
                for (; i >= 0; --i) {
                    if (idxs[i] != i + n - k) {
                        break;
                    }
                }
                return i;
            };
    
        vector<int> idxs(k);
        iota(begin(idxs), end(idxs), 0);
        callback(idxs);
        for (int i; (i = next_pos(n, k, idxs)) >= 0;) {
            ++idxs[i];
            for (int j = i + 1; j < k; ++j) {
                idxs[j] = idxs[j - 1] + 1;
            }
            callback(idxs);
        }
    }
};

// Time:  O(n^2 * 2^n)
// Space: O(n * 2^n)
// bfs based dp
class Solution2 {
public:
    int maximumCost(int n, vector<vector<int>>& highways, int k) {
        if (k + 1 > n) {  // required to optimize
            return -1;
        }
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& h : highways) {
            adj[h[0]].emplace_back(h[1], h[2]);
            adj[h[1]].emplace_back(h[0], h[2]);
        }
        vector<tuple<int, int, int>> dp;
        for (int u = 0; u < n; ++u) {
            dp.emplace_back(u, 1 << u, 0);
        }
        int result = -1;
        while (!empty(dp)) {
            vector<tuple<int, int, int>> new_dp;
            for (const auto& [u, mask, total] : dp) {
                if (__builtin_popcount(mask) == k + 1) {
                    result = max(result, total);
                }
                for (const auto& [v, t] : adj[u]) {
                    if (mask & (1 << v)) {
                        continue;
                    }
                    new_dp.emplace_back(v, mask | (1 << v), total + t);
                }
            }
            dp = move(new_dp);
        }
        return result;
    }
};
