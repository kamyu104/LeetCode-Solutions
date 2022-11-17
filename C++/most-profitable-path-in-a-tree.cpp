// Time:  O(n)
// Space: O(n)

// iterative dfs
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& iter_dfs = [&]() {
            vector<pair<int, int>> lookup(size(adj), {numeric_limits<int>::min(), numeric_limits<int>::max()});
            vector<tuple<int, int, int, int>> stk = {{1, 0, -1, 0}};
            while (!empty(stk)) {
                const auto [step, u, p, ah] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(2, u, p, ah);
                    for (const auto& v: adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        stk.emplace_back(1, v, u, ah + 1);
                    }
                } else if (step == 2) {
                    if ((size(adj[u]) + (u == 0) == 1)) {
                        lookup[u].first = 0;
                    }
                    if (u == bob) {
                        lookup[u].second = 0;
                    }
                    for (const auto& v: adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        lookup[u].first = max(lookup[u].first, lookup[v].first);
                        lookup[u].second = min(lookup[u].second, lookup[v].second);
                    }
                    if (ah == lookup[u].second) {
                        lookup[u].first += amount[u] / 2;
                    } else if (ah < lookup[u].second) {
                        lookup[u].first += amount[u];
                    }
                    if (lookup[u].second != numeric_limits<int>::max()) {
                        ++lookup[u].second;
                    }
                }
            }
            return lookup[0].first;
        };

        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs
class Solution2 {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> adj(size(edges) + 1);
        vector<bool> lookup(size(adj));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const function<pair<int, int>(int, int)> dfs = [&](int u, int ah) {
            lookup[u] = true;
            int result = (size(adj[u]) + (u == 0) == 1) ? 0 : numeric_limits<int>::min();
            int bh = (u == bob) ? 0 : numeric_limits<int>::max();
            for (const auto& v: adj[u]) {
                if (lookup[v]) {
                    continue;
                }
                const auto [r, h] = dfs(v, ah + 1);
                result = max(result, r);
                bh = min(bh, h);
            }
            if (ah == bh) {
                result += amount[u] / 2;
            } else if (ah < bh) {
                result += amount[u];
            }
            return pair(result, bh == numeric_limits<int>::max() ? bh : bh + 1);
        };

        return dfs(0, 0).first;
    }
};
