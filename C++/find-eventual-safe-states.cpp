// Time:  O(|V| + |E|)
// Space: O(|V|)

class Solution {
public:
    enum Color { WHITE, GRAY, BLACK };
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<Color> lookup(size(graph), WHITE);

        const function<bool(int)> dfs = [&](int node) {
            if (lookup[node] != WHITE) {
                return lookup[node] == BLACK;
            }
            lookup[node] = GRAY;
            if (any_of(cbegin(graph[node]), cend(graph[node]), [&](const auto& child) { return !dfs(child); })) {
                return false;
            }
            lookup[node] = BLACK;
            return true;
        };

        vector<int> result;
        for (int i = 0; i < size(graph); ++i) {
            if (dfs(i)) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
