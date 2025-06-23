// Time:  O(n)
// Space: O(n)

// mono deque, two pointers, sliding window, dp, prefix sum
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;

        deque<int> max_dq, min_dq;
        vector<int> dp(size(nums) + 1);
        dp[0] = 1;
        for (int right = 0, left = 0, suffix = 0; right < size(nums); ++right) {
            suffix = (suffix + dp[right]) % MOD;
            while (!empty(max_dq) && nums[max_dq.back()] <= nums[right]) {
                max_dq.pop_back();
            }
            max_dq.emplace_back(right);
            while (!empty(min_dq) && nums[min_dq.back()] >= nums[right]) {
                min_dq.pop_back();
            }
            min_dq.emplace_back(right);
            while (nums[max_dq[0]] - nums[min_dq[0]] > k) {
                if (max_dq[0] == left) {
                    max_dq.pop_front();
                }
                if (min_dq[0] == left) {
                    min_dq.pop_front();
                }
                suffix = (((suffix - dp[left++]) % MOD) + MOD) % MOD;
            }
            dp[right + 1] = suffix;
        }
        return dp.back();
    }
};
