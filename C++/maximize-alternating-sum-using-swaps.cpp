// Time:  O(n + s)
// Space: O(n + s)

// bfs, flood fill, quick select
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        vector<vector<int>> adj(size(nums));
        for (const auto& s : swaps) {
            adj[s[0]].emplace_back(s[1]);
            adj[s[1]].emplace_back(s[0]);
        }
        vector<bool> lookup(size(adj));
        const auto& bfs = [&](int u) {
            vector<int> q;
            if (lookup[u]) {
                return q;
            }
            lookup[u] = true;
            q.emplace_back(u);
            for (int i = 0; i < size(q); ++i) {
                for (const auto& v : adj[q[i]]) {
                    if (lookup[v]) {
                        continue;
                    }
                    lookup[v] = true;
                    q.emplace_back(v);
                }
            }
            return q;
        };

        int64_t result = accumulate(cbegin(nums), cend(nums), 0ll);
        for (int u = 0; u < size(nums); ++u) {
            const auto& g = bfs(u);
            if (empty(g)) {
                continue;
            }
            const int l = accumulate(cbegin(g), cend(g), 0, [](const auto& total, const auto& x) {
                return total + x % 2;
            });
            vector<int> arr;
            arr.reserve(size(g));
            for (const auto& i : g) {
                arr.emplace_back(nums[i]);
            }
            nth_element(begin(arr), begin(arr) + l, end(arr));
            result -= 2 * accumulate(cbegin(arr), cbegin(arr) + l, 0ll);
        }
        return result;
    }
};
