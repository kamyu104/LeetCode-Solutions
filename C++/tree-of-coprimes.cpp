// Time:  O(50 * n) = O(n)
// Space: O(n)

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        return iter_dfs(nums, adj);
    }

private:
    vector<int> iter_dfs(const vector<int>& nums, const unordered_map<int, vector<int>>& adj) {
        vector<int> result(size(nums), -1);
        unordered_map<int, vector<pair<int, int>>> path;
        vector<tuple<int, int, int, int>> stk = {{1, -1, 0, 0}};
        while (!empty(stk)) {
            const auto [step, prev, node, depth] = stk.back(); stk.pop_back();
            if (step == 1) {
                stk.emplace_back(4, -1, node, -1);
                stk.emplace_back(3, prev, node, depth);
                stk.emplace_back(2, -1, node, -1);
            } else if (step == 2) {
                int max_d = -1;
                for (const auto& [x, nodes] : path) {
                    if (gcd(nums[node], x) != 1) {
                        continue;
                    }
                    if (nodes.back().second > max_d) {
                        max_d = nodes.back().second;
                        result[node] = nodes.back().first;
                    }
                }
            } else if (step == 3) {
                path[nums[node]].emplace_back(node, depth);
                if (adj.count(node)) {
                    for (const auto& nei : adj.at(node)) {
                        if (nei == prev) {
                            continue;
                        }
                        stk.emplace_back(1, node, nei, depth + 1);
                    }
                }
            } else if (step == 4) {
                path[nums[node]].pop_back();
                if (empty(path[nums[node]])) {
                    path.erase(nums[node]);
                }
            }
        }
        return result;
    }
};

// Time:  O(50 * n) = O(n)
// Space: O(n)
class Solution2 {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> result(size(nums), -1);
        unordered_map<int, vector<pair<int, int>>> path;
        dfs(nums, adj, -1, 0, 0, &path, &result);
        return result;
    }

private:
    void dfs(const vector<int>& nums, const unordered_map<int, vector<int>>& adj,
             int prev, int node, int depth,
             unordered_map<int, vector<pair<int, int>>> *path,
             vector<int> *result) {
        int max_d = -1;
        for (const auto& [x, nodes] : *path) {
            if (gcd(nums[node], x) != 1) {
                continue;
            }
            if (nodes.back().second > max_d) {
                max_d = nodes.back().second;
                (*result)[node] = nodes.back().first;
            }
        }
        (*path)[nums[node]].emplace_back(node, depth);
        if (adj.count(node)) {
            for (const auto& nei : adj.at(node)) {
                if (nei == prev) {
                    continue;
                }
                dfs(nums, adj, node, nei, depth + 1, path, result);
            }
        }
        (*path)[nums[node]].pop_back();
        if (empty((*path)[nums[node]])) {
            (*path).erase(nums[node]);
        }
    }
};
