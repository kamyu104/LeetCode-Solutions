// Time:  O(n^2)
// Space: O(n^2)

// dp
class Solution {
public:
    int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) {
        vector<vector<int>> dp(size(nums), vector<int>(size(nums), numeric_limits<int>::min()));
        dp[0].back() = 0;
        for (int l = size(nums) - 1; l >= 1; --l) {
            for (int i = 0; i + (l - 1) < size(nums); ++i) {
                const int j = i + (l - 1);
                if (i - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + (nums[i - 1] >= queries[dp[i - 1][j]] ? 1 : 0));
                }
                if (j + 1 < size(nums)) {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + (nums[j + 1] >= queries[dp[i][j + 1]] ? 1 : 0));
                }
                if (dp[i][j] == size(queries)) {
                    return size(queries);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            result = max(result, dp[i][i] + (nums[i] >= queries[dp[i][i]] ? 1 : 0));
        }
        return result;
    }
};
