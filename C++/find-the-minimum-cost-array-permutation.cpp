// Time:  O((n-1)^2 * 2^(n-1))
// Space: O((n-1) * 2^(n-1))

// dp, backtracing
class Solution {
public:
    vector<int> findPermutation(vector<int>& nums) {
        static const int INF = numeric_limits<int>::max();

        const int n = size(nums);
        vector<vector<pair<int, int>>> dp(1 << (n - 1), vector<pair<int, int>>(n - 1, pair(INF, -1)));
        for (int i = 0; i + 1 < n; ++ i) {
            dp[1 << i][i] = {abs((i + 1) - nums[0]), -1};
        }            
        for (int mask = 0; mask < 1 << (n - 1); ++mask) {
            for (int i = 0; i + 1 < n; ++i) {
                if ((mask & (1 << i)) == 0) {
                    continue;
                }
                for (int j = 0; j + 1 < n; ++j) {
                    if (j == i || (mask & (1 << j)) == 0) {
                        continue;
                    }
                    dp[mask][i] = min(dp[mask][i], pair(dp[mask ^ (1 << i)][j].first + abs((i + 1) - nums[j + 1]), j));
                }
            }
        }
        int min_idx = -1;
        for (int i = 0; i + 1 < n; ++i) {
            if (min_idx == -1 || dp.back()[i].first + abs(0 - nums[i + 1]) < dp.back()[min_idx].first + abs(0 - nums[min_idx + 1])) {
                min_idx = i;
            }
        }        
        vector<int> result = {0};
        for (int i = min_idx, mask = (1 << (n - 1)) - 1; i != -1;
             tie(mask, i) = pair(mask ^ (1 << i), dp[mask][i].second)) {
            result.emplace_back(i + 1);
        }
        return result;
    }
};
