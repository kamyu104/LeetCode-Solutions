// Time:  O(k * n^2)
// Space: O(k * n)

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        static const int INF = numeric_limits<int>::max();

        ++k;
        vector<vector<int>> dp(size(nums) + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= size(nums); ++i) {
            int total = 0, max_num = 0;
            for (int j = i; j >= 1; --j) {
                total += nums[j - 1];
                max_num = max(max_num, nums[j - 1]);
                for (int m = 1; m <= k; ++m) {
                    if (dp[j - 1][m - 1] != INF) {
                        dp[i][m] = min(dp[i][m], dp[j - 1][m - 1] + (max_num * (i - j + 1) - total));
                    }
                }
            }
        }
        return dp.back().back();
    }
};
