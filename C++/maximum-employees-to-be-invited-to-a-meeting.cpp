// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        vector<vector<int>> inv_adj(size(favorite));
        for (int u = 0; u < size(favorite); ++u) {
            inv_adj[favorite[u]].emplace_back(u);
        }
        int result = 0, cycle_2s = 0;
        for (const auto& [u, l] : find_cycles(favorite)) {
            if (l > 2) {
                result = max(result, l);
                continue;
            }
            cycle_2s += bfs(inv_adj, u, favorite[u]) + bfs(inv_adj, favorite[u], u);
        }
        return max(result, cycle_2s);
    }

private:
    vector<pair<int, int>> find_cycles(const vector<int>& adj) {
        vector<pair<int, int>> result;
        vector<bool> lookup(size(adj));
        for (int i = 0; i < size(adj); ++i) {
            unordered_map<int, int> cnt;
            int u = i;
            while (!lookup[u]) {
                lookup[u] = true;
                cnt[u] = size(cnt);
                u = adj[u];
            }
            if (cnt.count(u)) {
                result.emplace_back(u, size(cnt) - cnt[u]);
            }
        }
        return result;
    }

    int bfs(const vector<vector<int>>& adj, int u, int exclude) {
        int result = 0;
        vector<int> q = {u};
        while (!empty(q)) {
            ++result;
            vector<int> new_q;
            for (const auto& u : q) {
                for (const auto& v : adj[u]) {
                    if (v == exclude) {
                        continue;
                    }
                    new_q.emplace_back(v);
                }
            }
            q = move(new_q);
        }
        return result;
    }
};
