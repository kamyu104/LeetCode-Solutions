// Time:  O(n * r), r = max(nums)
// Space: O(r)

// bitmasks, bfs
class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        const auto& bfs = [&]() {
            unordered_map<int, int> dist;
            dist[0] = 0;
            vector<int> q = {0};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& k : q) {
                    if (k == target) {
                        return dist[k];
                    }
                    for (const auto& x : nums) {
                        if (dist.count(k ^ x)) {
                            continue;
                        }
                        dist[k ^ x] = dist[k] + 1;
                        new_q.emplace_back(k ^ x);
                    }
                }
                q = move(new_q);
            }
            return -1;
        };

        for (const auto& x : nums) {
            target ^= x;
        }
        return bfs();
    }
};

// Time:  O(n * r), r = max(nums)
// Space: O(r)
// bitmasks, dp
class Solution2 {
public:
    int minRemovals(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (const auto& x : nums) {
            target ^= x;
            unordered_map<int, int> new_dp(dp);
            for (const auto& [k, _] : dp) {
                if (!new_dp.count(k ^ x) || new_dp[k ^ x] > dp[k] + 1) {
                    new_dp[k ^ x] = dp[k] + 1;
                }
            }
            dp = move(new_dp);
        }
        return dp.count(target) ? dp[target] : -1;
    }
};
