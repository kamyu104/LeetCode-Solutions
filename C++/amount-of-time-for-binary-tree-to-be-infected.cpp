// Time:  O(n)
// Space: O(h)

// iterative dfs, tree dp
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        const auto& iter_dfs = [&]() {
            int result = -1;
            using RET = pair<int, int>;
            RET ret = {-1, -1};
            vector<tuple<int, TreeNode *, shared_ptr<RET>, shared_ptr<RET>, RET *>> stk;
            stk.emplace_back(1, root, nullptr, nullptr, &ret);
            while (!empty(stk)) {
                auto [step, curr, left, right, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    if (!curr) {
                        continue;
                    }
                    auto left = make_shared<RET>(-1, -1), right = make_shared<RET>(-1, -1);
                    stk.emplace_back(2, curr, left, right, ret);
                    stk.emplace_back(1, curr->right, nullptr, nullptr, right.get());
                    stk.emplace_back(1, curr->left, nullptr, nullptr, left.get());
                } else if (step == 2) {
                    int d = -1;
                    if (curr->val == start) {
                        d = 0;
                        result = max(left->first, right->first) + 1;
                    } else if (left->second >= 0) {
                        d = left->second + 1;
                        result = max(result, right->first + 1 + d);
                    } else if (right->second >= 0) {
                        d = right->second + 1;
                        result = max(result, left->first + 1 + d);
                    }
                    *ret = make_pair(max(left->first, right->first) + 1, d);  // [height, dist_to_start]
                }
            }
            return result;
        };

        return iter_dfs();
    }
};


// Time:  O(n)
// Space: O(h)
// dfs, tree dp
class Solution2 {
public:
    int amountOfTime(TreeNode* root, int start) {
        int result = -1;

        const function<pair<int, int>(TreeNode *)> dfs = [&](TreeNode *curr) {
            if (!curr) {
                return make_pair(-1, -1);
            }
            const auto& left = dfs(curr->left);
            const auto& right = dfs(curr->right);
            int d = -1;
            if (curr->val == start) {
                d = 0;
                result = max(left.first, right.first) + 1;
            } else if (left.second >= 0) {
                d = left.second + 1;
                result = max(result, right.first + 1 + d);
            } else if (right.second >= 0) {
                d = right.second + 1;
                result = max(result, left.first + 1 + d);
            }
            return make_pair(max(left.first, right.first) + 1, d);  // [height, dist_to_start]
        };

        dfs(root);
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// bfs
class Solution3 {
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
