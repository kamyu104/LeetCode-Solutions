// Time:  O(nlogr), r = max(nums)
// Space: O(logr)

// dp
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> dp;
        for (const auto& x: nums) {
            unordered_map<int, int> new_dp;
            if (x % k == 0) {
                ++dp[x];
                for (const auto& [g, cnt] : dp) {
                    new_dp[gcd(g, x)] += cnt;
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
    int subarrayGCD(vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i, g = 0; j < size(nums); ++j) {
                if (nums[j] % k) {
                    break;
                }
                g = gcd(g, nums[j]);
                result += static_cast<int>(g == k);
            }
        }
        return result;
    }
};
