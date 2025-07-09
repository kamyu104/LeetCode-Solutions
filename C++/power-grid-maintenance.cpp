// Time:  O(c + n + q), n = len(connections)
// Space: O(c + n)

// dfs, flood fill, sort
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c);
        for (const auto& c : connections) {
            adj[c[0] - 1].emplace_back(c[1] - 1);
            adj[c[1] - 1].emplace_back(c[0] - 1);
        }
        vector<int> lookup(c, -1);
        const auto& iter_dfs = [&](int i) {
            vector<int> stk = {i};
            while (!empty(stk)) {
                const auto u = stk.back(); stk.pop_back();
                if (lookup[u] != -1) {
                    continue;
                }
                lookup[u] = i;
                for (const auto& v : adj[u]) {
                    stk.emplace_back(v);
                }
            }
        };

        for (int i = 0; i < c; ++i) {
            iter_dfs(i);
        }
        vector<vector<int>> groups(c);
        for (int i = c - 1; i >= 0; --i) {
            groups[lookup[i]].emplace_back(i);
        }
        vector<int> result;
        vector<bool> online(c, true);
        for (const auto& q : queries) {
            const auto t = q[0], x = q[1] - 1;
            if (t == 1) {
                if (online[x]) {
                    result.emplace_back(x + 1);
                    continue;
                }
                while (!empty(groups[lookup[x]]) && !online[groups[lookup[x]].back()]) {
                    groups[lookup[x]].pop_back();
                }
                result.emplace_back(!empty(groups[lookup[x]]) ? groups[lookup[x]].back() + 1 : -1);
            } else {
                online[x] = false;
            }
        }
        return result;
    }
};
