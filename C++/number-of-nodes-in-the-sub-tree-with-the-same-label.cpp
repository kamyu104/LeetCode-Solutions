// Time:  O(n)
// Space: O(h)

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> result(n);
        iter_dfs(labels, adj, 0, -1, &result);
        return result;
    }

private:
    void iter_dfs(
        const string& labels,
        const vector<vector<int>>& adj,
        int node, int parent, vector<int> *result) {
        using RET = vector<int>;
        RET ret(26);
        vector<tuple<int, int, int, int, shared_ptr<RET>, RET *>> stk = {{1, node, -1, -1, nullptr, &ret}};
        while (!stk.empty()) {
            const auto [step, node, parent, i, ret2, ret] = stk.back(); stk.pop_back();
            if (step == 1) {
                stk.emplace_back(4, node, -1, -1, nullptr, ret);
                stk.emplace_back(2, node, parent, adj[node].size() - 1, nullptr, ret);
            } else if (step == 2) {
                if (i < 0 || adj[node][i] == parent) {
                    continue;
                }
                const auto& ret2 = make_shared<vector<int>>(26);
                stk.emplace_back(2, node, parent, i - 1, nullptr, ret);
                stk.emplace_back(3, -1, -1, -1, ret2, ret);
                stk.emplace_back(1, adj[node][i], node, -1, nullptr, ret2.get());
            } else if (step == 3) {
                for (int k = 0; k < ret2->size(); ++k) {
                    (*ret)[k] += (*ret2)[k];
                }
            } else {
                (*result)[node] = ++(*ret)[labels[node] - 'a'];
            }
        }
    }
};

// Time:  O(n)
// Space: O(h)
class Solution_Recu {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> result(n);
        dfs(labels, adj, 0, -1, &result);
        return result;
    }

private:
    vector<int> dfs(
        const string& labels,
        const vector<vector<int>>& adj,
        int node, int parent, vector<int> *result) {
        vector<int> count(26);
        for (const auto& child : adj[node]) {
            if (child == parent) {
                continue;
            }
            const auto& new_count = dfs(labels, adj, child, node, result);
            for (int k = 0; k < new_count.size(); ++k) {
                count[k] += new_count[k];
            }
        }
        (*result)[node] = ++count[labels[node] - 'a'];
        return count;
    }
};
