// Time:  O(n^2)
// Space: O(n)

// dfs with recursion
class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        function<int(int, int, vector<int> *)> dfs = [&](int u, int p, vector<int> *result) {
            int total = nums[u];
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                total ^= dfs(v, u, result);
            }
            result->emplace_back(total);
            return total;
        };
        
        const int total = accumulate(cbegin(nums), cend(nums), 0,
                                     [](int x, int y) {
                                         return x ^ y;
                                     });
        int result = numeric_limits<int>::max();
        for (const auto& e : edges) {
            vector<vector<int>> xors(2);
            dfs(e[0], e[1], &xors[0]);
            dfs(e[1], e[0], &xors[1]);
            for (auto& candidates : xors) {
                const int total2 = candidates.back(); candidates.pop_back();
                for (const auto& x : candidates) {
                    const auto& [a, b, c] = tuple(total ^ total2, x, total2 ^ x);
                    result = min(result, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// dfs with stack
class Solution_TLE {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& iter_dfs = [&](int u, int p, vector<int> *result) {
            using RET = int;
            RET ret = 0;
            vector<tuple<int, int, int, shared_ptr<vector<shared_ptr<RET>>>, RET *>> stk;
            stk.emplace_back(1, u, p, nullptr, &ret);
            while (!empty(stk)) {
                auto [step, u, p, new_rets, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    auto new_rets = make_shared<vector<shared_ptr<RET>>>();
                    stk.emplace_back(2, u, p, new_rets, ret);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        new_rets->emplace_back(make_shared<RET>());
                        stk.emplace_back(1, v, u, nullptr, new_rets->back().get());
                    }
                } else if (step == 2) {
                    *ret = nums[u];
                    for (const auto& x : *new_rets) {
                        *ret ^= *x;
                    }
                    result->emplace_back(*ret);
                }
            }
        };
        
        const int total = accumulate(cbegin(nums), cend(nums), 0,
                                     [](int x, int y) {
                                         return x ^ y;
                                     });
        int result = numeric_limits<int>::max();
        for (const auto& e : edges) {
            vector<vector<int>> xors(2);
            iter_dfs(e[0], e[1], &xors[0]);
            iter_dfs(e[1], e[0], &xors[1]);
            for (auto& candidates : xors) {
                const int total2 = candidates.back(); candidates.pop_back();
                for (const auto& x : candidates) {
                    const auto& [a, b, c] = tuple(total ^ total2, x, total2 ^ x);
                    result = min(result, max({a, b, c}) - min({a, b, c}));
                }
            }
        }
        return result;
    }
};
