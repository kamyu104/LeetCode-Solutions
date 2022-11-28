// Time:  O(n)
// Space: O(h)

// iterative dfs
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };
        vector<vector<int>> adj(size(roads) + 1);
        for (const auto& r : roads) {
            adj[r[0]].emplace_back(r[1]);
            adj[r[1]].emplace_back(r[0]);
        }
        const auto& iter_dfs = [&]() {
            int64_t result = 0;
            using RET = int;
            RET ret{1};
            vector<tuple<int, int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, 0, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, p, d, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(3, u, p, d, new_ret, ret);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        const auto& new_ret = make_shared<RET>(1);
                        stk.emplace_back(2, v, u, d + 1, new_ret, ret);
                        stk.emplace_back(1, v, u, d + 1, nullptr, new_ret.get());
                    }
                } else if (step == 2) {
                    *ret += *new_ret;
                } else if (step == 3) {
                    if (d) {
                        result += ceil_divide(*ret, seats);
                    }
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
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };
        vector<vector<int>> adj(size(roads) + 1);
        for (const auto& r : roads) {
            adj[r[0]].emplace_back(r[1]);
            adj[r[1]].emplace_back(r[0]);
        }
        int64_t result = 0;
        const function<int(int, int, int)> dfs = [&](int u, int p, int d) {
            int cnt = 1;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                cnt += dfs(v, u, d + 1);
            }
            if (d) {
                result += ceil_divide(cnt, seats);
            }
            return cnt;
        };
        dfs(0, -1, 0);
        return result;
    }
};
