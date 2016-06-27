// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        sort(nums.begin(), nums.end());
        // dp[i]: the size of the largest distinct subset of
        //        the first i numbers including nums[i-1]
        vector<int> dp(nums.size() + 1, 1);
        vector<int> prev(nums.size(), -1);
        int largest_idx = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j < i; ++j) {
                if (nums[i - 1] % nums[j - 1] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i - 1] = j - 1;
                    }
                    if (dp[largest_idx] < dp[i]) {
                        largest_idx = i;
                    }
                }
            }
        }
        vector<int> result;
        for (int i = largest_idx - 1; i != -1; i = prev[i]) {
            result.emplace_back(nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
