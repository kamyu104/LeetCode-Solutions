// Time:  O(m * 2^m)
// Space: O(2^m)

// bitmasks, knapsack dp
class Solution {
public:
    vector<int> maxHammingDistances(vector<int>& nums, int m) {
        vector<int> dp(1 << m, -1);
        for (const auto& x: nums) {
            dp[x] = 0;
        }
        for (int i = 0; i < m; ++i) {
            vector<int> new_dp(dp);
            for (int mask = 0; mask < (1 << m); ++mask) {
                if (dp[mask ^ (1 << i)] != -1) {
                    new_dp[mask] = max(new_dp[mask], dp[mask ^ (1 << i)] + 1);
                }
            }
            dp = move(new_dp);
        }
        vector<int> result(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            result[i] = dp[nums[i]];
        }
        return result;
    }
};

// Time:  O(m * 2^m)
// Space: O(2^m)
// bitmasks, bfs
class Solution2 {
public:
    vector<int> maxHammingDistances(vector<int>& nums, int m) {
        vector<vector<int>> group(1 << m);
        for (int i = 0; i < size(nums); ++i) {
            group[((1 << m) - 1) ^ nums[i]].emplace_back(i);
        }
        vector<int> result(size(nums));
        vector<int> q;
        vector<int> lookup(1 << m);
        for (const auto& x : nums) {
            if (lookup[x]) {
                continue;
            }
            lookup[x] = true;
            q.emplace_back(x);
        }
        for (int d = 0; !empty(q); ++d) {
            vector<int> new_q;
            for (const auto& u : q) {
                for (const auto& i : group[u]) {
                    result[i] = m - d;
                }
                for (int i = 0; i < m; ++i) {
                    if (lookup[u ^ (1 << i)]) {
                        continue;
                    }
                    lookup[u ^ (1 << i)] = true;
                    new_q.emplace_back(u ^ (1 << i));
                }
            }
            q = move(new_q);
        }
        return result;
    }
};
