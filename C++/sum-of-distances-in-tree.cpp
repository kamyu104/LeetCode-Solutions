// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        vector<int> count(N, 1);
        vector<int> result(N, 0);

        dfs(graph, 0, -1, &count, &result);
        dfs2(graph, 0, -1, &count, &result);
        return result;
    }

private:
    void dfs(const unordered_map<int, vector<int>>& graph,
             int node, int parent,
             vector<int> *count, vector<int> *result) {
        if (!graph.count(node)) {
            return;
        }
        for (const auto& nei : graph.at(node)) {
            if (nei != parent) {
                dfs(graph, nei, node, count, result);
                (*count)[node] += (*count)[nei];
                (*result)[node] += (*result)[nei] + (*count)[nei];
            }
        }
    }

    void dfs2(const unordered_map<int, vector<int>>& graph,
             int node, int parent,
             vector<int> *count, vector<int> *result) {
        if (!graph.count(node)) {
            return;
        }
        for (const auto& nei : graph.at(node)) {
            if (nei != parent) {
                (*result)[nei] = (*result)[node] - (*count)[nei] +
                                 count->size() - (*count)[nei];
                dfs2(graph, nei, node, count, result);
            }
        }
    }
};
