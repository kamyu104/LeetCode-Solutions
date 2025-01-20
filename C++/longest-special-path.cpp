// Time:  O(n + e)
// Space: O(n + e)

// iterative dfs, two pointers, sliding window, prefix sum
class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<pair<int, int>>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        const auto& iter_dfs = [&]() {
            vector<int> result(2, numeric_limits<int>::max());
            unordered_map<int, int> lookup;
            vector<int> prefix = {0};
            vector<tuple<int, int, int, int, int, int, int>> stk = {{1, 0, -1, 0, -1, -1, -1}};
            while (!empty(stk)) {
                auto [step, u, p, d, left, i, prev_d] = stk.back(); stk.pop_back();
                if (step == 1) {
                    int prev_d;
                    tie(prev_d, lookup[nums[u] - 1]) = pair(lookup.count(nums[u] - 1) ? lookup[nums[u] - 1] : -1, d);
                    left = max(left, prev_d);
                    result = min(result, vector<int>{-(prefix[(d - 1) + 1] - prefix[left + 1]), d - left});
                    stk.emplace_back(4, u, -1, -1, -1, -1, prev_d);
                    stk.emplace_back(2, u, p, d, left, 0, -1);
                } else if (step == 2) {
                    if (i == size(adj[u])) {
                        continue;
                    }
                    stk.emplace_back(2, u, p, d, left, i + 1, -1);
                    auto [v, l] = adj[u][i];
                    if (v == p) {
                        continue;
                    }
                    prefix.emplace_back(prefix.back() + l);
                    stk.emplace_back(3, -1, -1, -1, -1, -1, -1);
                    stk.emplace_back(1, v, u, d+1, left, -1, -1);
                } else if (step == 3) {
                    prefix.pop_back();
                } else if (step == 4) {
                    lookup[nums[u] - 1] = prev_d;
                }
            }
            return vector<int>{-result[0], result[1]};
        };
    
        return iter_dfs();
    }
};

// Time:  O(n + e)
// Space: O(n + e)
// dfs, two pointers, sliding window, prefix sum
class Solution2 {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<pair<int, int>>> adj(size(nums));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }
        unordered_map<int, int> lookup;
        vector<int> prefix = {0};
        vector<int> result(2, numeric_limits<int>::max());
        const function<void (int, int, int, int)> dfs = [&](int u, int p, int d, int left) {
            int prev_d;
            tie(prev_d, lookup[nums[u] - 1]) = pair(lookup.count(nums[u] - 1) ? lookup[nums[u] - 1] : -1, d);
            left = max(left, prev_d);
            result = min(result, vector<int>{-(prefix[(d - 1) + 1] - prefix[left + 1]), d - left});
            for (const auto& [v, l] : adj[u]) {
                if (v == p) {
                    continue;
                }
                prefix.emplace_back(prefix.back() + l);
                dfs(v, u, d + 1, left);
                prefix.pop_back();
            }
            lookup[nums[u] - 1] = prev_d;
        };
    
        dfs(0, -1, 0, -1);
        return {-result[0], result[1]};
    }
};
