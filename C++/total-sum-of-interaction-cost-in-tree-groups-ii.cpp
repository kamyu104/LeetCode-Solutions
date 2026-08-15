// Time:  O(nlogn)
// Space: O(n)

// dfs, small-to-large merging
class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> adj(n);
        const auto& iter_dfs = [&]() {
            vector<int> order;
            vector<pair<int, int>> stk{{0, -1}};
            while (!empty(stk)) {
                const auto [u, p] = stk.back();
                stk.pop_back();
                order.emplace_back(u);
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    stk.emplace_back(v, u);
                }
            }
            return order;
        };

        vector<int64_t> total(n);
        const auto& count = [&](int g, int64_t c) {
            return c * (total[g] - c);
        };

        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        for (const auto& g : group) {
            ++total[g - 1];
        }
        vector<unordered_map<int, int64_t>> cnt(n);
        vector<int64_t> cnt2(n);
        int64_t result = 0;
        const auto& order = iter_dfs();
        for (const auto& u : order | views::reverse) {
            cnt[u][group[u] - 1] = 1;
            cnt2[u] = count(group[u] - 1, 1);
            for (const auto& v : adj[u]) {
                if (empty(cnt[v])) {
                    continue;
                }
                if (size(cnt[u]) < size(cnt[v])) {
                    swap(cnt[u], cnt[v]);
                    swap(cnt2[u], cnt2[v]);
                }
                for (const auto& [g, c] : cnt[v]) {
                    cnt2[u] -= count(g, cnt[u][g]);
                    cnt[u][g] += c;
                    cnt2[u] += count(g, cnt[u][g]);
                }
                cnt[v].clear();
            }
            result += cnt2[u];
        }
        return result;
    }
};
