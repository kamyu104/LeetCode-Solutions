// Time:  O(|V| + |E|)
// Space: O(|V|)

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> color;
        for (int node = 0; node < graph.size(); ++node) {
            if (color.count(node)) {
                continue;
            }
            vector<int> stack{node};
            color[node] = 0;
            while (!stack.empty()) {
                int curr = stack.back(); stack.pop_back();
                for (const auto& neighbor : graph[curr]) {
                    if (!color.count(neighbor)) {
                        stack.emplace_back(neighbor);
                        color[neighbor] = color[curr] ^ 1;
                    } else if (color[neighbor] == color[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
