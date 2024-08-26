// Time:  O(n * l^4)
// Space: O(n * l^2 + min(n * l^4, n^2)) = O(n * l^4)

// freq table, combinatorics
class Solution {
public:
    int countPairs(vector<int>& nums) {
        static const int L = 7;
        vector<int> POW10(L);
        POW10[0] = 1;
        for (int i = 0; i + 1 < L; ++i) {
            POW10[i+1] = POW10[i] * 10;
        }
        unordered_map<int, int> cnt1;
        for (const auto& x : nums) {
            ++cnt1[x];
        }
        unordered_map<int, vector<int>> adj;
        vector<pair<int, int>> cnt;
        for (const auto& [k, v] : cnt1) {
            cnt.emplace_back(k, v);
        }
        for (int idx = 0; idx < size(cnt); ++idx) {
            adj[cnt[idx].first].emplace_back(idx);
            for (int i = 0; i < L; ++i) {
                const int a = cnt[idx].first / POW10[i] % 10;
                for (int j = i + 1; j < L; ++j) {
                    const int b = cnt[idx].first /POW10[j] % 10;
                    if (a == b) {
                        continue;
                    }
                    adj[cnt[idx].first - a * (POW10[i] - POW10[j]) + b * (POW10[i] - POW10[j])].emplace_back(idx);
                }
            }
        }
        int result = 0;
        for (const auto& [_, v] : cnt1) {
            result += v * (v - 1) / 2;
        }
        unordered_map<int, unordered_set<int>> lookup;
        for (const auto& [u, _] : adj) {
            for (int i = 0; i < size(adj[u]); ++i) {
                const int v1 = cnt[adj[u][i]].second;
                for (int j = i + 1; j < size(adj[u]); ++j) {
                    const int v2 = cnt[adj[u][j]].second;
                    if (lookup[adj[u][i]].count(adj[u][j])) {
                        continue;
                    }
                    lookup[adj[u][i]].emplace(adj[u][j]);
                    result += v1 * v2;
                }
            }
        }
        return result;
    }
};

// Time:  O(n * l^4)
// Space: O(n + l^4) = O(n)
// freq table, combinatorics
class Solution2 {
public:
    int countPairs(vector<int>& nums) {
        static const int L = 7;
        vector<int> POW10(L);
        POW10[0] = 1;
        for (int i = 0; i + 1 < L; ++i) {
            POW10[i+1] = POW10[i] * 10;
        }
        const auto& at_most_2 = [&](int x) {
            unordered_set<int> result = {x};
            for (int i = 0; i < L; ++i) {
                const int a = x / POW10[i] % 10;
                for (int j = i + 1; j < L; ++j) {
                    const int b = x / POW10[j] % 10;
                    if (a == b) {
                        continue;
                    }
                    x += -a * (POW10[i] - POW10[j]) + b * (POW10[i] - POW10[j]);
                    result.emplace(x);
                    for (int k = 0; k < L; ++k) {
                        const int c = x / POW10[k] % 10;
                        for (int l = k + 1; l < L; ++l) {
                            const int d = x / POW10[l] % 10;
                            if (c == d) {
                                continue;
                            }
                            result.emplace(x - c * (POW10[k] - POW10[l]) + d * (POW10[k] - POW10[l]));
                        }
                    }
                    x -= -a * (POW10[i] - POW10[j]) + b * (POW10[i] - POW10[j]);
                }
            }
            return result;
        };

        int result = 0;
        unordered_map<int, int> cnt1;
        for (const auto& x : nums) {
            ++cnt1[x];
        }
        unordered_map<int, int> cnt2;
        for (const auto& [x, v] : cnt1) {
            result += cnt2[x] * v + v * (v - 1) / 2;
            for (const auto& x : at_most_2(x)) {
                if (!cnt1.count(x)) {
                    continue;
                }
                cnt2[x] += v;
            }
        }
        return result;
    }
};
