// Time:  O(t * n)
// Space: O(n)

// iterative dfs, tree dp
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<int> lookup(n);
        const auto& iter_dfs = [&](int u, int target) {
            vector<tuple<int, int, int, int>> stk = {{1, u, -1, target}};
            while (!empty(stk)) {
                const auto [step, u, p, target] = stk.back(); stk.pop_back();
                if (step == 1) {
                    ++lookup[u];
                    if (u == target) {
                        return;
                    }
                    stk.emplace_back(2, u, p, target);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        stk.emplace_back(1, v, u, target);
                    }
                } else if (step == 2) {
                    --lookup[u];
                }
            }
        };

        const auto& iter_dfs2 = [&]() {
            using RET = pair<int, int>;
            RET result = {price[0] * lookup[0], (price[0] / 2) * lookup[0]};
            vector<tuple<int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, nullptr, &result}};
            while (!empty(stk)) {
                const auto [step, u, p, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        const auto& new_ret = make_shared<RET>(price[v] * lookup[v], price[v] / 2 * lookup[v]);
                        stk.emplace_back(2, -1, -1, new_ret, ret);
                        stk.emplace_back(1, v, u, nullptr, new_ret.get());
                    }
                } else if (step == 2) {
                    ret->first += min(new_ret->first, new_ret->second);
                    ret->second += new_ret->first;
                }
            }
            return min(result.first, result.second);
        };

        for (const auto& t : trips) {
            iter_dfs(t[0], t[1]);
        }
        return iter_dfs2();
    }
};

// Time:  O(t * n)
// Space: O(n)
// dfs, tree dp
class Solution2 {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<int> lookup(n);
        const function<bool(int, int, int)> dfs = [&](int u, int p, int target) {
            ++lookup[u];
            if (u == target) {
                return true;
            }
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                if (dfs(v, u, target)) {
                    return true;
                }
            }
            --lookup[u];
            return false;
        };

        const function<pair<int, int>(int, int)> dfs2 = [&](int u, int p) {
            int full = price[u] * lookup[u], half = price[u] / 2 * lookup[u];
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& [f, h] = dfs2(v, u);
                full += min(f, h);
                half += f;
            }
            return pair(full, half);
        };

        for (const auto& t : trips) {
            dfs(t[0], -1, t[1]);
        }
        const auto& [f, h] = dfs2(0, -1);
        return min(f, h);
    }
};
