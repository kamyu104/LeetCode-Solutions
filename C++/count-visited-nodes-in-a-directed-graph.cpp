// Time:  O(n)
// Space: O(n)

// graph, hash table, stack
class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        const auto& find_cycles = [](const auto& adj) {
            vector<int> result(size(adj));
            vector<int> lookup(size(adj));
            vector<int> stk;  // added
            stk.reserve(size(adj));
            for (int i = 0, idx = 0; i < size(adj); ++i) {
                int u = i, prev = idx;
                while (!lookup[u]) {
                    lookup[u] = ++idx;
                    stk.emplace_back(u);  // added
                    u = adj[u];
                }
                if (lookup[u] > prev) {
                    const int l = idx - lookup[u] + 1;
                    for (int _ = 0; _ < l; ++_) {  // added
                        result[stk.back()] = l;
                        stk.pop_back();
                    }
                }
                while (!empty(stk))  {  // added
                    result[stk.back()] = result[adj[stk.back()]] + 1;
                    stk.pop_back();
                }
            }
            return result;
        };

        return find_cycles(edges);
    }
};
