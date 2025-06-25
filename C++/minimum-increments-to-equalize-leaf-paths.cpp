// Time:  O(n)
// Space: O(n)

// iterative dfs
class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& iter_dfs = [&]() {
            int result = n - 1;
            vector<int64_t> mx(n);
            vector<tuple<int, int, int>> stk = {{1, 0, -1}};
            while (!empty(stk)) {
                const auto [step, u, p] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(2, u, p);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        stk.emplace_back(1, v, u);
                    }
                } else if (step == 2) {
                    int cnt = 0;
                    for (const auto& v : adj[u]) {
                        if (v == p || mx[v] < mx[u]) {
                            continue;
                        }
                        if (mx[v] > mx[u]) {
                            mx[u] = mx[v];
                            cnt = 0;
                        }
                        ++cnt;
                    }
                    result -= cnt;
                    mx[u] += cost[u];
                }
            }
            return result;
        };

        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs
class Solution2 {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        int result = n - 1;
        const function<int64_t (int, int)> dfs = [&](int u, int p) {
            int64_t mx = 0;
            int cnt = 0;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& c = dfs(v, u);
                if (c < mx) {
                    continue;
                }
                if (c > mx) {
                    mx = c;
                    cnt = 0;
                }
                ++cnt;
            }
            result -= cnt;
            return mx + cost[u];
        };

        dfs(0, -1);
        return result;
    }
};
