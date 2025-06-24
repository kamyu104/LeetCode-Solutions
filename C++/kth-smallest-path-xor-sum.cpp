// Time:  O(n * (logn)^2 + qlogn)
// Space: O(n + q)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// iterative dfs, small-to-large merging, ordered set
class Solution {
public:
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        vector<vector<int>> adj(size(par));
        for (int u = 0; u < size(par); ++u) {
            const auto& p = par[u];
            if (p != -1) {
                adj[p].emplace_back(u);
            }
        }
        vector<vector<int>> lookup(size(adj));
        for (int i = 0; i < size(queries); ++i) {
            lookup[queries[i][0]].emplace_back(i);
        }
        const auto& iter_dfs = [&]() {
            using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
            vector<ordered_set> os(size(adj));
            vector<int> idxs(size(adj));
            iota(begin(idxs), end(idxs), 0);
            vector<int> result(size(queries), -1);
            vector<tuple<int, int, int>> stk = {{1, 0, 0}};
            while (!empty(stk)) {
                auto [step, u, curr] = stk.back(); stk.pop_back();
                if (step == 1) {
                    curr ^= vals[u];
                    os[idxs[u]].insert(curr);
                    stk.emplace_back(2, u, curr);
                    for (const auto& v : adj[u]) {
                        stk.emplace_back(1, v, curr);
                    }
                } else if (step == 2) {
                    for (const auto& v : adj[u]) {
                        if (size(os[idxs[u]]) < size(os[idxs[v]])) {
                            swap(idxs[u], idxs[v]);
                        }
                        for (const auto& x : os[idxs[v]]) {  // each node is merged at most O(logn) times
                            os[idxs[u]].insert(x);  // each add costs O(logn)
                        }
                    }
                    for (const auto& i : lookup[u]) {
                        if (queries[i][1] - 1 < size(os[idxs[u]])) {
                            result[i] = *(os[idxs[u]].find_by_order(queries[i][1] - 1));
                        }
                    }
                }
            }
            return result;
        };

        return iter_dfs();
    }
};

// Time:  O(n * (logn)^2 + qlogn)
// Space: O(n + q)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// dfs, small-to-large merging, ordered set
class Solution2 {
public:
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
        vector<vector<int>> adj(size(par));
        for (int u = 0; u < size(par); ++u) {
            const auto& p = par[u];
            if (p != -1) {
                adj[p].emplace_back(u);
            }
        }
        vector<vector<int>> lookup(size(adj));
        for (int i = 0; i < size(queries); ++i) {
            lookup[queries[i][0]].emplace_back(i);
        }
        vector<ordered_set> os(size(adj));
        vector<int> idxs(size(adj));
        iota(begin(idxs), end(idxs), 0);
        vector<int> result(size(queries), -1);
        const function<void (int, int)> dfs = [&](int u, int curr) {
            curr ^= vals[u];
            os[idxs[u]].insert(curr);
            for (const auto& v : adj[u]) {
                dfs(v, curr);
            }
            for (const auto& v : adj[u]) {
                if (size(os[idxs[u]]) < size(os[idxs[v]])) {
                    swap(idxs[u], idxs[v]);
                }
                for (const auto& x : os[idxs[v]]) {  // each node is merged at most O(logn) times
                    os[idxs[u]].insert(x);  // each add costs O(logn)
                }
            }
            for (const auto& i : lookup[u]) {
                if (queries[i][1] - 1 < size(os[idxs[u]])) {
                    result[i] = *(os[idxs[u]].find_by_order(queries[i][1] - 1));
                }
            }
        };

        dfs(0, 0);
        return result;
    }
};
