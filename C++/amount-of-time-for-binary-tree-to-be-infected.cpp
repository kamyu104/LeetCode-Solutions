// Time:  O(n)
// Space: O(n)

// bfs
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        const auto& bfs = [](const auto& root) {
            unordered_map<int, vector<int>> adj;
            vector<TreeNode *> q = {root};
            while (!empty(q)) {
                vector<TreeNode *> new_q;
                for (const auto& u : q) {
                    for (const auto& v : {u->left, u->right}) {
                        if (!v) {
                            continue;
                        }
                        adj[u->val].emplace_back(v->val);
                        adj[v->val].emplace_back(u->val);
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return adj;
        };
        
        const auto& bfs2 = [](const auto& adj, const auto& start) {
            int result = -1;
            vector<int> q = {start};
            unordered_set<int> lookup = {start};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    if (!adj.count(u)) {
                        continue;
                    }
                    for (const auto& v : adj.at(u)) {
                        if (lookup.count(v)) {
                            continue;
                        }
                        lookup.emplace(v);
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
                ++result;
            }
            return result;
        };

        const auto& adj = bfs(root);
        return bfs2(adj, start);
    }
};
