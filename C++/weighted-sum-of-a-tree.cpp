// Time:  O(n)
// Space: O(n)

// tree dp
class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        vector<int> lookup(size(nums), -1);
        lookup[0] = 0;
        for (int i = 1; i < size(nums); ++i) {
            int d = 0, j = i;
            for (; lookup[j] == -1; j = parent[j]) {
                ++d;
            }
            d += lookup[j];
            for (int j = i; lookup[j] == -1; j = parent[j]) {
                lookup[j] = d--;
            }
        }
        const auto& h = ranges::max(lookup);
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            result += nums[i] * (h - lookup[i] + 1LL);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// dfs
class Solution2 {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        vector<vector<int>> adj(size(nums));
        const auto& iter_dfs = [&]() {
            vector<int> lookup(size(nums));
            vector<pair<int, int>> stk = {{0, 0}};
            while (!empty(stk)) {
                const auto [u, d] = stk.back(); stk.pop_back();
                lookup[u] = d;
                for (const auto& v : adj[u]) {
                    stk.emplace_back(v, d + 1);
                }
            }
            return lookup;
        };

        for (int i = 1; i < size(parent); ++i) {
            adj[parent[i]].emplace_back(i);
        }
        const auto& lookup = iter_dfs();
        const auto& h = ranges::max(lookup);
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            result += nums[i] * (h - lookup[i] + 1LL);
        }
        return result;
    }
};
