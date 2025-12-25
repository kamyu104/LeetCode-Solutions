// Time:  O(n * g)
// Space: O(n * g)

// bfs
class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& mx = ranges::max(group);
        vector<int64_t> total(mx);
        for (const auto& x : group) {
            ++total[x - 1];
        }
        int64_t result = 0;
        const auto& bfs = [&]() {
            vector<int> order = {0};
            vector<int> parent(n, -1);
            for (int i = 0; i < size(adj); ++i) {
                const auto u = order[i];
                for (const auto& v : adj[u]) {
                    if (v == parent[u]) {
                        continue;
                    }
                    parent[v] = u;
                    order.emplace_back(v);
                }
            }
            return pair(order, parent);
        };
        
        const auto& [order, parent] = bfs();
        vector<vector<int64_t>> cnt(n, vector<int64_t>(mx));
        for (int i = size(order) - 1; i >= 0; --i) {
            const auto& u = order[i];
            ++cnt[u][group[u] - 1];
            for (const auto& v : adj[u]) {
                if (u != parent[v]) {
                    continue;
                }
                for (int k = 0; k < size(cnt[v]); ++k) {
                    result += cnt[v][k] * (total[k] - cnt[v][k]);
                    cnt[u][k] += cnt[v][k];
                }
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// bfs, small-to-large merging
class Solution2 {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        } 
        unordered_map<int, int64_t> total;
        for (const auto& x : group) {
            ++total[x];
        }
        int64_t result = 0;
        const auto& bfs = [&]() {
            vector<int> order = {0};
            vector<int> parent(n, -1);
            for (int i = 0; i < size(adj); ++i) {
                const auto u = order[i];
                for (const auto& v : adj[u]) {
                    if (v == parent[u]) {
                        continue;
                    }
                    parent[v] = u;
                    order.emplace_back(v);
                }
            }
            return pair(order, parent);
        };
        
        const auto& [order, parent] = bfs();
        vector<unordered_map<int, int64_t>> cnt(n);
        for (int i = size(order) - 1; i >= 0; --i) {
            const auto& u = order[i];
            ++cnt[u][group[u]];
            for (const auto& v : adj[u]) {
                if (u != parent[v]) {
                    continue;
                }
                for (const auto& [k, c] : cnt[v]) {
                    result += c * (total[k] - c);
                }
                if (size(cnt[v]) > size(cnt[u])) {
                    swap(cnt[u], cnt[v]);
                }
                for (const auto& [k, c] : cnt[v]) {
                    cnt[u][k] += c;
                }
                cnt[v].clear();
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// dfs, small-to-large merging
class Solution3 {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        } 
        unordered_map<int, int64_t> total;
        for (const auto& x : group) {
            ++total[x];
        }
        int64_t result = 0;
        const auto dfs = [&](this auto&& dfs, int u, int p) -> unordered_map<int, int64_t> {
            unordered_map<int, int64_t> cnt;
            ++cnt[group[u]];
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                auto new_cnt = dfs(v, u);
                for (const auto& [k, c] : new_cnt) {
                    result += c * (total[k] - c);
                }
                if (size(new_cnt) > size(cnt)) {
                    swap(cnt, new_cnt);
                }
                for (const auto& [k, c] : new_cnt) {
                    cnt[k] += c;
                }
            }
            return cnt;
        };
        
        dfs(0, -1);
        return result;
    }
};
