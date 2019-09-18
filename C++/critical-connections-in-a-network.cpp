// Time:  O(|V| + |E|)
// Space: O(|V| + |E|)

// variant of Tarjan's algorithm (https://www.geeksforgeeks.org/bridge-in-a-graph/)
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges(n);
        int idx = 0;
        vector<int> lowlinks(n);
        vector<bool> lookup(n);
        vector<vector<int>> result;
        for (const auto& c : connections) {
            edges[c.front()].emplace_back(c.back());
            edges[c.back()].emplace_back(c.front());
        }
        dfs(edges, -1, 0, &idx, &lowlinks, &lookup, &result);
        return result;
    }

private:
    void dfs(const vector<vector<int>>& edges,
             int parent, int u,
             int *idx, vector<int> *lowlinks,
             vector<bool> *lookup, vector<vector<int>> *result) {

        if ((*lookup)[u]) {
            return;
        }
        (*lookup)[u] = true;
        const auto curr_idx = (*lowlinks)[u] = (*idx)++;
        for (const auto& v : edges[u]) {
            if (v == parent) {
                continue;
            }
            dfs(edges, u, v, idx, lowlinks, lookup, result);
            (*lowlinks)[u] = min((*lowlinks)[u], (*lowlinks)[v]);
            if ((*lowlinks)[v] > curr_idx) {
                // if any lowlink of neighbors is larger than curr_idx
                result->push_back({u, v});
            }
        }
    }
};
