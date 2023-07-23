// Time:  O(n)
// Space: O(n)

// iterative dfs, freq table
class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        vector<vector<int>> adj(size(parent));
        for (int u = 0; u < size(parent); ++u) {
            if (parent[u] != -1) {
                adj[parent[u]].emplace_back(u);
            }
        }
        const auto& iter_dfs = [&]() {
            int64_t result = 0;
            vector<pair<int, int>> stk = {{0, 0}};
            while (!empty(stk)) {
                auto [u, mask] = stk.back(); stk.pop_back();
                if (u) {
                    mask ^= 1 << (s[u] - 'a');
                    for (int i = 0; i < 26; ++i) {
                        if (cnt.count(mask ^ (1 << i))) {
                            result += cnt[mask ^ (1 << i)];
                        }
                    }
                    result += cnt[mask]++;
                }
                for (const auto& v : adj[u]) {
                    stk.emplace_back(v, mask);
                }
            }
            return result;
        };
        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, freq table
class Solution2 {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        vector<vector<int>> adj(size(parent));
        for (int u = 0; u < size(parent); ++u) {
            if (parent[u] != -1) {
                adj[parent[u]].emplace_back(u);
            }
        }
        const function<int64_t (int, int)> dfs = [&](int u, int mask) {
            int64_t result = 0;
            if (u) {
                mask ^= 1 << (s[u] - 'a');
                for (int i = 0; i < 26; ++i) {
                    if (cnt.count(mask ^ (1 << i))) {
                        result += cnt[mask ^ (1 << i)];
                    }
                }
                result += cnt[mask]++;
            }
            for (const auto& v : adj[u]) {
                result += dfs(v, mask);
            }
            return result;
        };
        return dfs(0, 0);
    }
};
