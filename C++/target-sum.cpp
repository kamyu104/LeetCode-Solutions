// Time:  O(n * S)
// Space: O(S)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // sum(P) - sum(N) = S
        //       <=>
        // 2 * sum(P) = S + sum(nums)
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (S + sum) % 2) {
            return 0;
        }
        return subsetSum(nums, (S + sum) / 2); 
    }   

private:
    int subsetSum(vector<int>& nums, int S) {
        vector<int> dp(S + 1);
        dp[0] = 1;
        for (const auto& n : nums) {
            for (int i = S; i >= n; --i) {
                dp[i] += dp[i - n];
            }
        }
        return dp.back();
    }
};
