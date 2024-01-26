// Time:  O(n^2)
// Space: O(n^2)

// dp
class Solution {
public:
    int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) {
        static const int NEG_INF = numeric_limits<int>::min();

        vector<vector<int>> dp(size(nums), vector<int>(size(nums), NEG_INF));
        dp[0].back() = 0;
        for (int l = size(nums) - 1; l >= 1; --l) {
            for (int i = 0; i + (l - 1) < size(nums); ++i) {
                const int j = i + (l - 1);
                const int left = i - 1 >= 0 ? dp[i - 1][j] : NEG_INF;
                const int right = j + 1 < size(nums) ? dp[i][j + 1] : NEG_INF;
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
