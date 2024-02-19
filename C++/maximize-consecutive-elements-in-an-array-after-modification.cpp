// Time:  O(nlogn)
// Space: O(1)

// sort, dp
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int result = 1;
        vector<int> dp(2, 1);
        for (int i = 1; i < size(nums); ++i) {
            if (nums[i] == nums[i - 1]) {
                dp[1] = dp[0] + 1;
            } else if (nums[i] == nums[i - 1] + 1) {
                ++dp[0];
                ++dp[1];
            } else if (nums[i] == nums[i - 1] + 2) {
                dp[0] = dp[1] + 1;
                dp[1] = 1;
            } else {
                dp[0] = dp[1] = 1;
            }
            result = max({result, dp[0], dp[1]});
        }
        return result;
    }
};


// Time:  O(nlogn)
// Space: O(n)
// sort, dp
class Solution2 {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int result = 1;
        unordered_map<int, int> dp;
        for (const auto& x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;
            result = max({result, dp[x + 1], dp[x]});
        }
        return result;
    }
};
