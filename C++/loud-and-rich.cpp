// Time:  O(q + r)
// Space: O(q + r)

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> graph(quiet.size());
        for (const auto& r : richer) {
            graph[r[1]].emplace_back(r[0]);
        }
        vector<int> result(quiet.size(), -1);
        for (int i = 0; i < quiet.size(); ++i) {
            dfs(graph, quiet, i, &result);
        }
        return result;
    }

private:
    int dfs(const vector<vector<int>>& graph,
            const vector<int>& quiet,
            int node, vector<int> *result) {
        if ((*result)[node] == -1) {
            (*result)[node] = node;
            for (const auto& nei : graph[node]) {
                int smallest_person = dfs(graph, quiet, nei, result);
                if (quiet[smallest_person] < quiet[(*result)[node]]) {
                    (*result)[node] = smallest_person;
                }
            }
        }
        return (*result)[node];
    }
};
