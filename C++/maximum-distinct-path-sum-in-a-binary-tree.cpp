// Time:  O(n^2)
// Space: O(n)

// bfs, iterative dfs
class Solution {
public:
    int maxSum(TreeNode* root) {
        const auto& bfs = [&]() {
            vector<vector<int>> adj(1);
            vector<int> vals = {root->val};
            vector<pair<TreeNode*, int>> q = {{root, 0}};
            while (!empty(q)) {
                vector<pair<TreeNode*, int>> new_q;
                for (const auto& [u, p] : q) {
                    vals.emplace_back(u->val);
                    adj.emplace_back();
                    const auto& i = size(adj) - 1;
                    if (p != -1) {
                        adj[i].emplace_back(p);
                        adj[p].emplace_back(i);
                    }
                    for (const auto& node : {u->left, u->right}) {
                        if (!node) {
                            continue;
                        }
                        new_q.emplace_back(node, i);
                    }
                }
                q = move(new_q);
            }
            return pair(adj, vals);
        };

        const auto& [adj, vals] = bfs();
        const auto iter_dfs = [&](int u) {
            int result = numeric_limits<int>::min();
            int total = 0;
            unordered_set<int> lookup;
            vector<tuple<int, int, int>> stk = {{1, u, -1}};
            while (!empty(stk)) {
                const auto [step, u, p] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (lookup.count(vals[u])) {
                        continue;
                    }
                    stk.emplace_back(2, u, p);
                    lookup.emplace(vals[u]);
                    total += vals[u];
                    result = max(result, total);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        stk.emplace_back(1, v, u);
                    }
                } else if (step == 2) {
                    total -= vals[u];
                    lookup.erase(vals[u]);
                }
            }
            return result;

        };
        int result = numeric_limits<int>::min();
        for (int u = 0; u < size(adj); ++u) {
            result = max(result, iter_dfs(u));
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// dfs
class Solution2 {
public:
    int maxSum(TreeNode* root) {
        vector<vector<int>> adj;
        vector<int> vals;
        const auto dfs1 = [&](this auto&& dfs1, TreeNode *u, int p) -> void {
            vals.emplace_back(u->val);
            adj.emplace_back();
            const auto& i = size(adj) - 1;
            if (p != -1) {
                adj[i].emplace_back(p);
                adj[p].emplace_back(i);
            }
            for (const auto& node : {u->left, u->right}) {
                if (!node) {
                    continue;
                }
                dfs1(node, i);
            }
        };

        unordered_set<int> lookup;
        const auto dfs2 = [&](this auto&& dfs2, int u, int p) {
            if (lookup.count(vals[u])) {
                return numeric_limits<int>::min();
            }
            lookup.emplace(vals[u]);
            int mx = 0;
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                mx = max(mx, dfs2(v, u));
            }
            lookup.erase(vals[u]);
            return vals[u] + mx;
        };

        dfs1(root, -1);
        int result = numeric_limits<int>::min();
        for (int u = 0; u < size(adj); ++u) {
            result = max(result, dfs2(u, -1));
        }
        return result;
    }
};
