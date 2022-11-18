// Time:  O(n * sqrt(k) * logk)
// Space: O(sqrt(k))

// dp
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> dp;
        for (const auto& x: nums) {
            unordered_map<int, int> new_dp;
            if (k % x == 0) {
                ++dp[x];
                for (const auto& [l, cnt] : dp) {
                    new_dp[lcm(l, x)] += cnt;
                }
            }
            dp = new_dp;
            result += dp[k];
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(1)
// brute force
class Solution2 {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i, l = 1; j < size(nums); ++j) {
                if (k % nums[j]) {
                    break;
                }
                l = lcm(l, nums[j]);
                result += static_cast<int>(l == k);
            }
        }
        return result;
    }
};
