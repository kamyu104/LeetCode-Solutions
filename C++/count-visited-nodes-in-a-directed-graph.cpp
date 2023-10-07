// Time:  O(n)
// Space: O(n)

// graph, prefix sum, two pointers, sliding window
class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        const auto& find_cycles = [](const auto& adj) {
            vector<int> result(size(adj));
            vector<int> lookup(size(adj));
            vector<int> lookup2(size(adj));  // added
            for (int i = 0, idx = 0; i < size(adj); ++i) {
                int u = i, prev = idx;
                while (!lookup[u]) {
                    lookup[u] = ++idx;
                    lookup2[idx - 1] = u;  // added
                    u = adj[u];
                }
                if (lookup[u] > prev) {
                    const int l = idx - lookup[u] + 1;
                    for (int _ = 0; _ < l; ++_, u = adj[u]) {  // added
                        result[u] = l;
                    }
                }
                for (int j = lookup[u] > prev ? (lookup[u] - 1) - 1 : idx - 1; j >= prev; --j)  { // added
                    result[lookup2[j]] = result[adj[lookup2[j]]] + 1;
                }
            }
            return result;
        };

        return find_cycles(edges);
    }
};
