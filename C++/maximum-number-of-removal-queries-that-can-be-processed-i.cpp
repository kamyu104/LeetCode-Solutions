// Time:  O(n^2)
// Space: O(n^2)

// dp
class Solution {
public:
    int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) {
        vector<vector<int>> dp(size(nums), vector<int>(size(nums)));
        for (int l = size(nums) - 1; l >= 1; --l) {
            for (int i = 0; i + (l - 1) < size(nums); ++i) {
                const int j = i + (l - 1);
                const int left = i - 1 >= 0 ? dp[i - 1][j] : 0;
                const int right = j + 1 < size(nums) ? dp[i][j + 1] : 0;
                dp[i][j] = max(left, right);
                if (i - 1 >= 0 && nums[i - 1] >= queries[left]) {
                    dp[i][j] = max(dp[i][j], left + 1);
                }
                if (j + 1 < size(nums) && nums[j + 1] >= queries[right]) {
                    dp[i][j] = max(dp[i][j], right + 1);
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
