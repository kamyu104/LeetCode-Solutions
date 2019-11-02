// Time:  O(|V| + |E|)
// Space: O(|E|)

class Solution {
private:
	template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        int length = 0;
        for (const auto& edge : edges) {
            graph[edge[0]].emplace(edge[1]);
            graph[edge[1]].emplace(edge[0]);
        }
        unordered_set<pair<int, int>, PairHash<int>> curr_level;
        for (const auto& [u, neighbors] : graph) {
            if (neighbors.size() == 1) {
                curr_level.emplace(-1, u);
            }
        }
        while (!curr_level.empty()) {
            unordered_set<pair<int, int>, PairHash<int>> new_level;
            for (const auto& [prev, u] : curr_level) {
                for (const auto& v : graph[u]) {
                    if (v != prev) {
                        new_level.emplace(u, v);
                    }
                }
            }
            curr_level = move(new_level);
            ++length;
        }
        return max(length - 1, 0);
    }
};
