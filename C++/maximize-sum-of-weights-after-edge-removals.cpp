// Time:  O(n)
// Space: O(n)

// iterative dfs, quick select
class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        vector<vector<pair<int, int>>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        const auto& iter_dfs = [&]() {
            vector<pair<int64_t, int64_t>> cnt(size(adj));
            vector<tuple<int, int, int>> stk = {{1, 0, -1}};
            while (!empty(stk)) {
                const auto [step, u, p] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(2, u, p);
                    for (const auto& [v, w] : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        stk.emplace_back(1, v, u);
                    }
                } else if (step == 2) {
                    int64_t curr = 0;
                    vector<int64_t> diff;
                    for (const auto& [v, w] : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        curr += cnt[v].first;
                        diff.emplace_back(max((cnt[v].second + w) - cnt[v].first, static_cast<int64_t>(0)));
                    }
                    if (k - 1 < size(diff)) {
                        nth_element(begin(diff), begin(diff) + (k - 1), end(diff), greater<int>());
                    }
                    cnt[u] = pair(accumulate(cbegin(diff), cbegin(diff) + min(k, static_cast<int>(size(diff))), curr),
                                  accumulate(cbegin(diff), cbegin(diff) + min(k - 1, static_cast<int>(size(diff))), curr));
                }
            }
            return cnt[0].first;
        };

        return iter_dfs();
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, quick select
class Solution2 {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        vector<vector<pair<int, int>>> adj(size(edges) + 1);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        const function<pair<int64_t, int64_t>(int, int)> dfs = [&](int u, int p) {
            int64_t result = 0;
            vector<int64_t> diff;
            for (const auto& [v, w] : adj[u]) {
                if (v == p) {
                    continue;
                }
                const auto& cnt = dfs(v, u);
                result += cnt.first;
                diff.emplace_back(max((cnt.second + w) - cnt.first, static_cast<int64_t>(0)));
            }
            if (k - 1 < size(diff)) {
                nth_element(begin(diff), begin(diff) + (k - 1), end(diff), greater<int>());
            }

            return pair(accumulate(cbegin(diff), cbegin(diff) + min(k, static_cast<int>(size(diff))), result),
                        accumulate(cbegin(diff), cbegin(diff) + min(k - 1, static_cast<int>(size(diff))), result));
        };

        return dfs(0, -1).first;
    }
};
