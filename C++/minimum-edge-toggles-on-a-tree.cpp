// Time:  O(n)
// Space: O(n)

// greedy, topological sort, bitmasks
class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            if (start[i] != target[i]) {
                diff[i] = 1;
            }
        }
        if (accumulate(cbegin(diff), cend(diff), 0) % 2) {
            return {-1};
        }
        vector<int> degree(n), adj(n), edge(n);
        for (int idx = 0; idx < size(edges); ++idx) {
            const auto& u = edges[idx][0], &v = edges[idx][1];
            ++degree[u];
            ++degree[v];
            adj[u] ^= v;
            adj[v] ^= u;
            edge[u] ^= idx;
            edge[v] ^= idx;
        }
        vector<bool> lookup(size(edges));
        for (int i = 0; i < n; ++i) {
            int u = i;
            while (degree[u] == 1) {
                const auto v = adj[u];
                const auto idx = edge[u];
                --degree[u];
                --degree[v];
                adj[u] ^= v;
                adj[v] ^= u;
                edge[u] ^= idx;
                edge[v] ^= idx;
                if (diff[u]) {
                    diff[u] ^= 1;
                    diff[v] ^= 1;
                    lookup[idx] = true;
                }
                u = v;
            }
        }
        vector<int> result;
        for (int i = 0; i < size(lookup); ++i) {
            if (lookup[i]) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// greedy, topological sort
class Solution2 {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            if (start[i] != target[i]) {
                diff[i] = 1;
            }
        }
        if (accumulate(cbegin(diff), cend(diff), 0) % 2) {
            return {-1};
        }
        vector<int> degree(n);
        vector<vector<pair<int, int>>> adj(n);
        const auto& topological_sort = [&]() {
            vector<bool> lookup(size(adj));
            vector<int> q;
            for (int u = 0; u < size(adj); ++u) {
                if (size(adj[u]) == 1) {
                    q.emplace_back(u);
                }
            }
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& [v, idx] : adj[u]) {
                        if (degree[v] == 0) {
                            continue;
                        }
                        --degree[u];
                        --degree[v];
                        if (degree[v] == 1) {
                            new_q.emplace_back(v);
                        }
                        if (diff[u]) {
                            diff[u] ^= 1;
                            diff[v] ^= 1;
                            lookup[idx] = true;
                        }
                    }
                }
                q = move(new_q);
            }
            return lookup;
        };

        for (int idx = 0; idx < size(edges); ++idx) {
            const auto& u = edges[idx][0], &v = edges[idx][1];
            ++degree[u];
            ++degree[v];
            adj[u].emplace_back(v, idx);
            adj[v].emplace_back(u, idx);
        }
        const auto& lookup = topological_sort();
        vector<int> result;
        for (int i = 0; i < size(lookup); ++i) {
            if (lookup[i]) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
