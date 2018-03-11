// Time:  O(p + r * n), p is the count of all the possible paths in graph,
//                      r is the count of the result.
// Space: O(n)

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path{0};
        dfs(graph, 0, &path, &result);
        return result;
    }

private:
    void dfs(const vector<vector<int>>& graph,
             int curr, vector<int> *path,
             vector<vector<int>> *result) {
        if (curr == graph.size() - 1) {
            result->emplace_back(*path);
            return;
        }
        for (const auto& node: graph[curr]) {
            path->emplace_back(node);
            dfs(graph, node, path, result);
            path->pop_back();
        }        
    }
};
