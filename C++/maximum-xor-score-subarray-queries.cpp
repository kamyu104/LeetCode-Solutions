// Time:  O(n^2 + q)
// Space: O(n^2)

// dp
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> dp(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            dp[i].resize(size(nums) - i);
            dp[i][0] = nums[i];
        }
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (int l = 1; l + i < size(nums); ++l) {
                dp[i][l] = dp[i][l - 1] ^ dp[i + 1][l - 1];
            }
        }
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (int l = 1; l + i < size(nums); ++l) {
                dp[i][l] = max({dp[i][l], dp[i][l - 1], dp[i + 1][l - 1]});
            }
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            result[i] = dp[queries[i][0]][queries[i][1] - queries[i][0]];
        }
        return result;
    }
};

// Time:  O(n^2 + q)
// Space: O(n^2)
// dp
class Solution2 {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> dp(size(nums), vector<int>(size(nums)));
        for (int i = 0; i < size(nums); ++i) {
            dp[i][i] = nums[i];
        }
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (int j = i + 1; j < size(nums); ++j) {
                dp[i][j] = dp[i][j - 1] ^ dp[i + 1][j];
            }
        }
        for (int i = size(nums) - 1; i >= 0; --i) {
            for (int j = i + 1; j < size(nums); ++j) {
                dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i + 1][j]});
            }
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            result[i] = dp[queries[i][0]][queries[i][1]];
        }
        return result;
    }
};
