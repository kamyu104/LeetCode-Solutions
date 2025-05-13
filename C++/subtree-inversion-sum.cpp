// Time:  O(n)
// Space: O(n)

// iterative dfs, tree dp
class Solution {
public:
    long subtreeInversionSum(const vector<vector<int>>& edges, const vector<int>& nums, int k) {
        vector<vector<int>> adj(size(nums));
        vector<pair<int64_t, int64_t>> dp;
        const auto& iter_dfs = [&]() {
            vector<pair<int64_t, int64_t>> dp;
            using RET = vector<int64_t>;
            RET ret(3);
            vector<tuple<int, int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, -1, nullptr, &ret}};
            while (!empty(stk)) {
                const auto [step, u, p, i, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    dp.emplace_back(0, 0);
                    (*ret) = {nums[u], 0, 0};
                    stk.emplace_back(4, u, p, -1, nullptr, ret);
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
                    const auto& new_ret = make_shared<RET>(3);
                    stk.emplace_back(3, u, p, i, new_ret, ret);
                    stk.emplace_back(1, v, u, -1, nullptr, new_ret.get());
                } else if (step == 3) {
                    (*ret)[0] += (*new_ret)[0];
                    (*ret)[1] += (*new_ret)[1];
                    (*ret)[2] += (*new_ret)[2];
                } else if (step == 4) {
                    (*ret)[1] = max((*ret)[1], dp.back().second - 2 * (*ret)[0]);
                    (*ret)[2] = max((*ret)[2], dp.back().first + 2 * (*ret)[0]);
                    dp.pop_back();
                    if (size(dp) >= k) {
                        dp[size(dp) - k].first += (*ret)[1];
                        dp[size(dp) - k].second += (*ret)[2];
                    }
                }
            }
            return ret[0] + ret[1];
        };

        for (const auto& e: edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, tree dp
class Solution2 {
public:
    long subtreeInversionSum(const vector<vector<int>>& edges, const vector<int>& nums, int k) {
        vector<vector<int>> adj(size(nums));
        vector<pair<int64_t, int64_t>> dp;
        const function<tuple<int64_t, int64_t, int64_t> (int, int)> dfs = [&](int u, int p) {
            dp.emplace_back(0, 0);
            int64_t total = nums[u];
            int64_t pos = 0;
            int64_t neg = 0;
            for (const auto& v: adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& [new_total, new_pos, new_neg] = dfs(v, u);
                total += new_total;
                pos += new_pos;
                neg += new_neg;
            }
            pos = max(pos, dp.back().second - 2 * total);
            neg = max(neg, dp.back().first + 2 * total);
            dp.pop_back();
            if (size(dp) >= k) {
                dp[size(dp) - k].first += pos;
                dp[size(dp) - k].second += neg;
            }
            return tuple(total, pos, neg);
        };

        for (const auto& e: edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        const auto& [total, pos, neg] = dfs(0, -1);
        return total + pos;
    }
};
