// Time:  O(n)
// Space: O(h)

// iterative dfs
class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(edges) + 1);
        int result = 0;
        const auto& iter_dfs = [&]() {
            int64_t result = 0;
            using RET = int;
            RET ret{};
            vector<tuple<int, int, int, int, shared_ptr<RET>, shared_ptr<int>, shared_ptr<bool>, RET *>> stk = {{1, 0, -1, -1, nullptr, nullptr, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, p, i, new_ret, l, valid, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    const auto& new_l = make_shared<int>();
                    const auto& new_valid = make_shared<bool>(true);
                    stk.emplace_back(4, -1, -1, -1, nullptr, nullptr, new_valid, ret);
                    stk.emplace_back(2, u, p, 0, nullptr, new_l, new_valid, ret);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    stk.emplace_back(2, u, p, i + 1, nullptr, l, valid, ret);
                    const auto& v = adj[u][i];
                    if (v == p) {
                        continue;
                    }
                    const auto& new_ret = make_shared<RET>();
                    stk.emplace_back(3, -1, -1, -1, new_ret, l, valid, ret);
                    stk.emplace_back(1, v, u, -1, nullptr, nullptr, nullptr, new_ret.get());
                } else if (step == 3) {
                    (*ret) += (*new_ret);
                    ++(*l);
                    if ((*new_ret) * (*l) != (*ret)) {
                        (*valid) = false;
                    }
                } else if (step == 4) {
                    if (*valid) {
                        ++result;
                    }
                    ++(*ret);
                }
            }
            return result;
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(h)
// dfs
class Solution2 {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(edges) + 1);
        int result = 0;
        const function<int (int, int)> dfs = [&](int u, int p) {
            int total = 0, l = 0;
            bool valid = true;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                const int cnt = dfs(v, u);
                total += cnt;
                ++l;
                if (cnt * l != total) {
                    valid = false;
                }
            }
            if (valid) {
                ++result;
            }
            return total + 1;
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        dfs(0, -1);
        return result;
    }
};
