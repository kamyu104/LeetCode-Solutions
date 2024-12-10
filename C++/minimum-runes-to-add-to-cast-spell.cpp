// Time:  O(n)
// Space: O(n)

// tarjan's algorithm, SCC, strongly connected compoenents
class Solution {
public:
    int minRunesToAdd(int n, vector<int>& crystals, vector<int>& flowFrom, vector<int>& flowTo) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < size(flowFrom); ++i) {
            adj[flowFrom[i]].emplace_back(flowTo[i]);
        }
        const auto& sccs = strongly_connected_components(adj);
        vector<int> lookup(n, -1);
        for (int i = 0; i < size(sccs); ++i) {
            for (const auto& x : sccs[i]) {
                lookup[x] = i;
            }
        }
        vector<bool> result(size(sccs));
        for (int u = 0; u < n; ++u) {
            for (const auto& v : adj[u]) {
                if (lookup[v] != lookup[u]) {
                    result[lookup[v]] = true;
                }
            }
        }
        for (const auto& x : crystals) {
            result[lookup[x]] = true;
        }
        return accumulate(cbegin(result), cend(result), 0, [](const auto& accu, const auto& x) {
            return accu + !x;
        });
    }

private:
    // reference: https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm
    vector<vector<int>> strongly_connected_components(const vector<vector<int>>& adj) {
        int index_counter = 0;
        vector<int> index(size(adj), -1), lowlinks(size(adj), -1);
        vector<int> stack;
        vector<bool> stack_set(size(adj));
        vector<vector<int>> result;
        for (int v = 0; v < size(adj); ++v) {
            if (index[v] == -1) {
                strongconnect(adj, v, index_counter, index, lowlinks, stack, stack_set, result);
            }
        }
        return result;
    }

    void strongconnect(const auto& adj, int v, auto& index_counter, auto& index, auto& lowlinks, auto& stack, auto& stack_set, auto& result) {
        index[v] = index_counter;
        lowlinks[v] = index_counter;
        ++index_counter;
        stack_set[v] = true;
        stack.emplace_back(v);
        for (const auto& w : adj[v]) {
            if (index[w] == -1) {
                strongconnect(adj, w, index_counter, index, lowlinks, stack, stack_set, result);
                lowlinks[v] = min(lowlinks[v], lowlinks[w]);
            } else if (stack_set[w]) {
                lowlinks[v] = min(lowlinks[v], index[w]);
            }
        }
        if (lowlinks[v] == index[v]) {
            vector<int> connected_component;
            int w = -1;
            while (w != v) {
                w = stack.back(); stack.pop_back();
                stack_set[w] = false;
                connected_component.emplace_back(w);
            }
            result.emplace_back(move(connected_component));
        }
    };
};
