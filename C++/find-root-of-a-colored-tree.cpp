// Time:  O(n)
// Space: O(n)

// graph
class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        static const unordered_map<char, int> LOOKUP = {{'R', 0}, {'B', 1}, {'W', 2}};

        vector<int> in_degree(size(edges) + 1);
        vector<int> out_degree(size(edges) + 1);
        for (const auto& e : edges) {
            auto u = e[0], v = e[1];
            const auto& x = LOOKUP.at(colors[u]), &y = LOOKUP.at(colors[v]);
            if (x == y) {
                return -1;
            }
            if ((x + 1) % 3 != y) {
                swap(u, v);
            }
            ++out_degree[u];
            ++in_degree[v];
        }
        return ranges::max(out_degree) <= 2 && ranges::max(in_degree) <= 1 ? distance(cbegin(in_degree), find(cbegin(in_degree), cend(in_degree), 0)) : -1;
    }
};
