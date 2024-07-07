// Time:  O(n)
// Space: O(1)

// prefix sum, greedy
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int result = 0;
        for (int i = size(nums) - 1, mx = 0; i >= 1; --i) {
            mx = max(mx, nums[i]);
            result += mx;
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// dp
class Solution2 {
public:
    int maxScore(vector<int>& nums) {
        vector<int> dp(size(nums));
        for (int i = 1; i < size(nums); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = max(dp[i], dp[j] + (i - j) * nums[i]);
            }
        }
        return dp.back();
    }
};
