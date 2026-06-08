// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int64_t result = 0;
        for (int i = 0; i < size(nums);) {
            if (s[i] == '0') {
                ++i;
                continue;
            }
            result += (i - 1 >= 0) ? nums[i - 1] : 0;
            int mn = (i - 1 >= 0) ? nums[i - 1] : 0;
            int j = i;
            for (; j < size(nums) && s[j] == '1'; ++j) {
                result += nums[j];
                mn = min(mn, nums[j]);
            }
            result -= mn;
            i = j;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// dp
class Solution2 {
public:
    long long maxTotal(vector<int>& nums, string s) {
        static const int64_t NEG_INF = numeric_limits<int64_t>::min();

        vector<int64_t> dp(2, NEG_INF);
        dp[0] = 0;
        for (int i = 0; i < size(nums); ++i) {
            vector<int64_t> new_dp(2, NEG_INF);
            if (s[i] == '0') {
                new_dp[0] = ranges::max(dp);
            } else {
                new_dp[1] = ranges::max(dp) + nums[i];
                if (i - 1 >= 0) {
                    if (dp[0] != NEG_INF) {
                        new_dp[0] = dp[0] + nums[i - 1];
                    }
                }
            }
            dp = move(new_dp);
        }
        return ranges::max(dp);
    }
};
