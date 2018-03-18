// Time:  O(|V| + |E|)
// Space: O(|V|)

class Solution {
public:
    enum Color { WHITE, GRAY, BLACK };
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        unordered_map<int, Color> lookup;
        for (int i = 0; i < graph.size(); ++i) {
            if (dfs(graph, i, &lookup)) {
                result.emplace_back(i);
            }
        }
        return result;
    }

private:
    bool dfs(const vector<vector<int>>& graph, int node,
             unordered_map<int, Color> *lookup) {
        if ((*lookup)[node] != WHITE) {
            return (*lookup)[node] == BLACK;
        }
        (*lookup)[node] = GRAY;
        for (const auto& child : graph[node]) {
            if ((*lookup)[child] == BLACK) {
                continue;
            }
            if ((*lookup)[child] == GRAY ||
                !dfs(graph, child, lookup)) {
                return false;
            }
        }
        (*lookup)[node] = BLACK;
        return true;
    }
};
