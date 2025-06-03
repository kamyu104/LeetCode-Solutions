// Time:  O(n * b)
// Space: O(n + b)

// iterative dfs, tree dp
class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> adj(n);
        const auto& iter_dfs = [&]() {
            using RET = vector<unordered_map<int, int>>;
            RET ret(2);
            vector<tuple<int, int, int, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, nullptr, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, i, new_ret, dp, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    const auto& dp = make_shared<RET>(2);
                    (*dp)[0][0] = (*dp)[1][0] = 0;
                    stk.emplace_back(4, u, -1, nullptr, dp, ret);
                    stk.emplace_back(2, u, 0, nullptr, dp, nullptr);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    const auto& v = adj[u][i];
                    stk.emplace_back(2, u, i + 1, nullptr, dp, nullptr);
                    const auto& new_ret = make_shared<RET>(2);
                    stk.emplace_back(3, -1, -1, new_ret, dp, nullptr);
                    stk.emplace_back(1, v, -1, nullptr, nullptr, new_ret.get());
                } else if (step == 3) {
                    vector<unordered_map<int, int>> new_dp(2);
                    for (int i = 0; i < 2; ++i) {
                        for (const auto& [j1, v1] : (*dp)[i]) {
                            for (const auto& [j2, v2] : (*new_ret)[i]) {
                                if (j1 + j2 <= budget) {
                                    new_dp[i][j1 + j2] = max(new_dp[i][j1 + j2], v1 + v2);
                                }
                            }
                        }
                    }
                    *dp = move(new_dp);
                } else if (step == 4) {
                    for (int i = 0; i < 2; ++i) {
                        for (const auto& [j, v] : (*dp)[0]) {
                            (*ret)[i][j] = max((*ret)[i][j], v);
                        }
                        const int cost = present[u] >> i;
                        if (cost > budget) {
                            continue;
                        }
                        const int profit = future[u] - cost;
                        for (const auto& [j, v] : (*dp)[1]) {
                            if (j + cost <= budget) {
                                (*ret)[i][j + cost] = max((*ret)[i][j + cost], v + profit);
                            }
                        }
                    }
                }
            }
            int result = 0;
            for (const auto& [_, v] : ret[0]) {
                result = max(result, v);
            }
            return result;
        };

        for (const auto& h: hierarchy) {
            adj[h[0] - 1].emplace_back(h[1] - 1);
        }
        return iter_dfs();
    }
};

// Time:  O(n * b)
// Space: O(n + b)
// dfs, tree dp
class Solution2 {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> adj(n);
        const function<vector<unordered_map<int, int>> (int)> dfs = [&](int u) {
            vector<unordered_map<int, int>> dp(2);
            dp[0][0] = dp[1][0] = 0;
            for (const auto& v : adj[u]) {
                const auto& res = dfs(v);
                vector<unordered_map<int, int>> new_dp(2);
                for (int i = 0; i < 2; ++i) {
                    for (const auto& [j1, v1] : dp[i]) {
                        for (const auto& [j2, v2] : res[i]) {
                            if (j1 + j2 <= budget) {
                                new_dp[i][j1 + j2] = max(new_dp[i][j1 + j2], v1 + v2);
                            }
                        }
                    }
                }
                dp = move(new_dp);
            }
            vector<unordered_map<int, int>> result(2);
            for (int i = 0; i < 2; ++i) {
                for (const auto& [j, v] : dp[0]) {
                    result[i][j] = max(result[i][j], v);
                }
                const int cost = present[u] >> i;
                if (cost > budget) {
                    continue;
                }
                const int profit = future[u] - cost;
                for (const auto& [j, v] : dp[1]) {
                    if (j + cost <= budget) {
                        result[i][j + cost] = max(result[i][j + cost], v + profit);
                    }
                }
            }
            return result;  // result[i][j]: max profit for budget j with i discount
        };

        for (const auto& h: hierarchy) {
            adj[h[0] - 1].emplace_back(h[1] - 1);
        }
        const auto& ret = dfs(0);
        int result = 0;
        for (const auto& [_, v] : ret[0]) {
            result = max(result, v);
        }
        return result;
    }
};
