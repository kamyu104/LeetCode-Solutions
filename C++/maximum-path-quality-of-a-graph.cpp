// Time:  O(|V| + |E| + 4^(maxTime/min(times))) = O(|V| + |E| + 4^10)
// Space: O(|V| + |E|)

class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vector<vector<pair<int, int>>> adj(size(values));
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }
        return iter_dfs(values, adj, maxTime);
    }

private:
    int iter_dfs(const vector<int>& values,
                 const vector<vector<pair<int, int>>>& adj,
                 int maxTime) {

        unordered_map<int, int> lookup;
        unordered_map<int, unordered_set<int>> lookup2;
        int result = 0;
        vector<tuple<int, int, int, int, int>> stk = {{1, 0, -1, maxTime, 0}};
        while (!empty(stk)) {
            auto [step, u, v, time, total] = stk.back(); stk.pop_back();
            if (step == 1) {
                if (++lookup[u] == 1) {
                    total += values[u];
                }
                if (!u) {
                    result = max(result, total);
                }
                stk.emplace_back(4, u, -1, -1, -1);
                for (const auto& [v, t] : adj[u]) {
                    if (lookup2[u].count(v) || time < t) {
                        continue;
                    }
                    stk.emplace_back(3, u, v, -1, -1);
                    stk.emplace_back(1, v, -1, time - t, total);
                    stk.emplace_back(2, u, v, -1, -1);  // same directed edge won't be visted twice
                }
            } else if (step == 2) {
                lookup2[u].emplace(v);
            } else if (step == 3) {
                lookup2[u].erase(v);
            } else if (step == 4) {
                --lookup[u];
            }
        }
        return result;
    }
};


// Time:  O(|V| + |E| + 4^(maxTime/min(times))) = O(|V| + |E| + 4^10)
// Space: O(|V| + |E|)
class Solution2 {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vector<vector<pair<int, int>>> adj(size(values));
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }
        unordered_map<int, int> lookup;
        unordered_map<int, unordered_set<int>> lookup2;
        int result = 0;
        dfs(values, adj, 0, maxTime, 0, &lookup, &lookup2, &result);
        return result;
    }

private:
    void dfs(const vector<int>& values,
             const vector<vector<pair<int, int>>>& adj,
             int u, int time, int total,
             unordered_map<int, int> *lookup,
             unordered_map<int, unordered_set<int>> *lookup2,
             int *result) {

        if (++(*lookup)[u] == 1) {
            total += values[u];
        }
        if (!u) {
            *result = max(*result, total);
        }
        for (const auto& [v, t] : adj[u]) {
            if ((*lookup2)[u].count(v) || time < t) {
                continue;
            }
            (*lookup2)[u].emplace(v);  // same directed edge won't be visted twice
            dfs(values, adj, v, time - t, total, lookup, lookup2, result);
            (*lookup2)[u].erase(v);
        }
        --(*lookup)[u];
    }
};
