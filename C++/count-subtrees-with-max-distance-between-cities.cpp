// Time:  O(n^6)
// Space: O(n^3)

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        vector<int> lookup(n), result(n - 1);
        for (int i = 0; i < n; ++i) {  // Time: sum(O(k^5) for k in [1, n]) = O(n^6)
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));
            vector<int> count(n, 1);
            dfs(n, adj, i, -1, lookup, &count, &dp);  // Time: O(k^5), k is the number of the remaining cities
            lookup[i] = 1;
            for (int d = 1; d < n; ++d) {  // for each depth from city i
                for (int max_d = d; max_d < min(2 * d + 1, n); ++max_d) {  // for each max distance
                    result[max_d - 1] += dp[i][d][max_d];
                }
            }
        }
        return result;
    }

private:
    void dfs(int n, const vector<vector<int>>& adj,
             int curr, int parent,
             const vector<int>& lookup,
             vector<int> *count,
             vector<vector<vector<int>>> *dp) {
    
        for (const auto& child : adj[curr]) {
            if (child == parent || lookup[child]) {
                continue;
            }
            dfs(n, adj, child, curr, lookup, count, dp);
        }
        (*dp)[curr][0][0] = 1;
        for (const auto& child : adj[curr]) {
            if (child == parent || lookup[child]) {
                continue;
            }
            vector<vector<int>> new_dp_curr = (*dp)[curr];
            for (int curr_d = 0; curr_d < (*count)[curr]; ++curr_d) {
                for (int curr_max_d = curr_d; curr_max_d < min(2 * curr_d + 1, (*count)[curr]); ++curr_max_d) {
                    if (!(*dp)[curr][curr_d][curr_max_d]) {  // pruning
                        continue;
                    }
                    for (int child_d = 0; child_d < (*count)[child]; ++child_d) {
                        for (int child_max_d = child_d; child_max_d < min(2 * child_d + 1, (*count)[child]); ++child_max_d) {
                            new_dp_curr[max(curr_d, child_d + 1)][max({curr_max_d, child_max_d, curr_d + child_d + 1})] +=
                                (*dp)[curr][curr_d][curr_max_d] * (*dp)[child][child_d][child_max_d];  // count subtrees with new child
                        }
                    }
                }
            }
            (*count)[curr] += (*count)[child];  // merge new child
            (*dp)[curr] = move(new_dp_curr);
        }
    }
};

// Time:  O(n * 2^n)
// Space: O(n)
class Solution2 {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        vector<int> result(n - 1);
        int total = 1 << n;
        for (int mask = 1; mask < total; ++mask) {
            int max_d = maxDistance(n, edges, adj, mask);
            if (max_d - 1 >= 0) {
                ++result[max_d - 1];
            }
        }
        return result;
    }

private:
    int maxDistance(int n,
                    const vector<vector<int>>& edges,
                    const vector<vector<int>>& adj,
                    int mask) {
        const auto& [is_valid, farthest, max_d] = bfs(n, adj, mask, log(mask & -mask) / log(2));
        return is_valid ? get<2>(bfs(n, adj, mask, farthest)) : 0;
    }
    
    tuple<bool, int, int> bfs(int n, const vector<vector<int>>& adj,
                              int mask, int start) {
        queue<pair<int, int>> q({{start, 0}});
        int lookup = (1 << start);
        int count = __builtin_popcount(mask) - 1, u = -1, d = -1;
        while (!empty(q)) {
            tie(u, d) = move(q.front()); q.pop();
            for (const auto& v : adj[u]) {
                if (!(mask & (1 << v)) || (lookup & (1 << v))) {
                    continue;
                }
                lookup |= (1 << v);
                --count;
                q.emplace(v, d + 1);
            }
        }
        return {count == 0, u, d};
    }
};
