// Time:  O(n)
// Space: O(n)

// iterative dfs, hash table
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        vector<vector<int>> adj(size(parent));
        for (int v = 0; v < size(parent); ++v) {
            if (parent[v] != -1) {
                adj[parent[v]].emplace_back(v);
            }
        }
        const auto& iter_dfs = [&]() {
            vector<vector<int>> lookup(26);
            vector<int> result(size(parent), 1);
            vector<pair<int, int>> stk = {{1, 0}};
            while (!empty(stk)) {
                const auto [step, u] = stk.back(); stk.pop_back();
                if (step == 1) {
                    lookup[s[u] - 'a'].emplace_back(u);
                    stk.emplace_back(2, u);
                    for (const auto& v : adj[u]) {
                        stk.emplace_back(1, v);
                    }
                } else if (step == 2) {
                    for (const auto& v : adj[u]) {
                        const auto i = !empty(lookup[s[v] - 'a']) ? lookup[s[v] - 'a'].back() : u;
                        result[i] += result[v];
                    }
                    lookup[s[u] - 'a'].pop_back();
                }
            }
            return result;
        };

        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, hash table
class Solution2 {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        vector<vector<int>> adj(size(parent));
        for (int v = 0; v < size(parent); ++v) {
            if (parent[v] != -1) {
                adj[parent[v]].emplace_back(v);
            }
        }
        vector<vector<int>> lookup(26);
        vector<int> result(size(parent), 1);
        const function<void (int)> dfs = [&](int u) {
            lookup[s[u] - 'a'].emplace_back(u);
            for (const auto& v : adj[u]) {
                dfs(v);
                const auto i = !empty(lookup[s[v] - 'a']) ? lookup[s[v] - 'a'].back() : u;
                result[i] += result[v];
            }
            lookup[s[u] - 'a'].pop_back();
        };

        dfs(0);
        return result;
    }
};
