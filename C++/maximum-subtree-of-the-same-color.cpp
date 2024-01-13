// Time:  O(n)
// Space: O(h)

// iterative dfs
class Solution {
public:
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        vector<vector<int>> adj(size(colors));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        
        const auto& iter_dfs = [&]() {
            int result = 0;
            using RET = int;
            RET ret{1};
            vector<tuple<int, int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, -1, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, p, i, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(4, -1, -1, -1, nullptr, ret);
                    stk.emplace_back(2, u, p, 0, nullptr, ret);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& v = adj[u][i];
                    stk.emplace_back(2, u, p, i + 1, nullptr, ret);
                    if (v == p) {
                        continue;
                    }
                    const auto& new_ret = make_shared<RET>(1);
                    stk.emplace_back(3, u, p, i, new_ret, ret);
                    stk.emplace_back(1, v, u, -1, nullptr, new_ret.get());
                } else if (step == 3) {
                    const auto& v = adj[u][i];
                    if (*ret == -1) {
                        continue;
                    }
                    if (*new_ret == -1 || colors[v] != colors[u]) {
                        *ret = -1;
                        continue;
                    }
                    *ret += *new_ret;
                } else if (step == 4) {
                    result = max(result, *ret);
                }
            }
            return result;
        };

        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(h)
// dfs
class Solution2 {
public:
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        vector<vector<int>> adj(size(colors));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        int result = 0;
        const function<int (int, int)> dfs = [&](int u, int p) {
            int cnt = 1;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto c = dfs(v, u);
                if (cnt == -1) {
                    continue;
                }
                if (c == -1 || colors[v] != colors[u]) {
                    cnt = -1;
                    continue;
                }
                cnt += c;
            }
            result = max(result, cnt);
            return cnt;
        };

        dfs(0, -1);
        return result;
    }
};
