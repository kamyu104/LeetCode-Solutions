// Time:  O(r^2 + n * r), r = max(nums)
// Space: O(r^2)

// dp
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int result = 2;
        const int mx = ranges::max(nums);
        vector<vector<int>> dp(mx, vector<int>(mx));
        for (auto x : nums){
            --x;
            for (int nx = 0; nx < size(dp[x]); ++nx){
                const int d = abs(nx - x);
                dp[x][d] = max(dp[x][d], dp[nx][d] + 1);
            }
            for (int d = size(dp[x]) - 2; d >= 0; --d){
                dp[x][d] = max(dp[x][d], dp[x][d + 1]);
            }
            result = max(result, dp[x][0]);
        }
        return result;
    }
};

// Time:  O(r^2 + n * r), r = max(nums)
// Space: O(r^2)
// dp
class Solution2 {
public:
    int longestSubsequence(vector<int>& nums) {
        int result = 2;
        const int mx = ranges::max(nums);
        vector<vector<int>> dp(mx, vector<int>(mx));
        for (int i = size(nums) - 1; i >= 0; --i){
            const int x = nums[i] - 1;
            for (int nx = 0; nx < size(dp[x]); ++nx){
                const int d = abs(nx - x);
                dp[x][d] = max(dp[x][d], dp[nx][d] + 1);
            }
            for (int d = 1; d < size(dp[x]); ++d){
                dp[x][d] = max(dp[x][d], dp[x][d - 1]);
            }
            result = max(result, dp[x].back());
        }
        return result;
    }
};
