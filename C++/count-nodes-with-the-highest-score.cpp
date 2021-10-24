// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>> adj(size(parents));  // Space: O(n)
        for (int i = 1; i < size(parents); ++i) {
            adj[parents[i]].emplace_back(i);
        }
        return iter_dfs(adj);
    }
private:
    int iter_dfs(const vector<vector<int>>& adj) {
        pair<int64_t, int> result;
        using RET = shared_ptr<int>;
        auto ret = make_shared<int>();
        vector<tuple<int, int, vector<RET>, RET>> stk;
        stk.emplace_back(1, 0, vector<RET>(), ret);
        while (!empty(stk)) {
            auto [step, i, cnts, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                vector<RET> cnts(size(adj[i]));
                for (auto& cnt : cnts) {
                    cnt = make_shared<int>();
                }
                stk.emplace_back(2, i, cnts, ret);
                for (int j = 0; j < size(adj[i]); ++j) {
                    stk.emplace_back(1, adj[i][j], vector<RET>(), cnts[j]);
                }
            } else if (step == 2) {
                *ret = accumulate(cbegin(cnts), cend(cnts), 0,
                                  [](const auto& total, const auto& x) {
                                      return total + *x;
                                  }) + 1;
                const int64_t score = max(static_cast<int64_t>(size(adj)) - *ret, 1l) *
                                      accumulate(cbegin(cnts), cend(cnts), 1ul,
                                                 [](const auto& total, const auto& x) {
                                                     return total * *x;
                                                 });
                if (score > result.first) {
                    result = {score, 1};
                } else if (score == result.first) {
                    ++result.second;
                }
            }
        }
        return result.second;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>> adj(size(parents));  // Space: O(n)
        for (int i = 1; i < size(parents); ++i) {
            adj[parents[i]].emplace_back(i);
        }
        pair<int64_t, int> result;
        dfs(adj, 0, &result);
        return result.second;
    }
private:
    int dfs(const vector<vector<int>>& adj, int i, pair<int64_t, int> *result) {
        vector<int> cnts;
        for (const auto& child : adj[i]) {
            cnts.emplace_back(dfs(adj, child, result));
        }
        const int total = accumulate(cbegin(cnts), cend(cnts), 0) + 1;
        const int64_t score = max(static_cast<int64_t>(size(adj)) - total, 1l) *
                              accumulate(cbegin(cnts), cend(cnts), 1ul,
                                         [](const auto& total, const auto& x) {
                                             return total * x;
                                         });
        if (score > result->first) {
            *result = {score, 1};
        } else if (score == result->first) {
            ++result->second;
        }
        return total;
    }
};
