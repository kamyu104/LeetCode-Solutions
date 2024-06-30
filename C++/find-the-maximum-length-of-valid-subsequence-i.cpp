// Time:  O(n * k)
// Space: O(k)

// dp
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        static const int k = 2;

        int result = 0;
        for (int i = 0; i < k; ++i) {
            vector<int> dp(k);
            for (const auto& x : nums) {
                dp[x % k] = dp[((i - x) % k + k) % k] + 1;
            }
            result = max(result, ranges::max(dp));
        }
        return result;
    }
};

// Time:  O(n * k)
// Space: O(k)
// brute force
class Solution2 {
public:
    int maximumLength(vector<int>& nums) {
        int result = 1;
        for (int i = 0; i + 1 < size(nums); ++i) {
            if (nums[i] % 2 != nums[i + 1] % 2) {
                ++result;
            }
        }
        return max({
            accumulate(cbegin(nums), cend(nums), 0, [](const auto& total, const auto& x) {
                return total + (x % 2 == 0 ? 1 : 0);
            }), accumulate(cbegin(nums), cend(nums), 0, [](const auto& total, const auto& x) {
                return total + (x % 2 == 1 ? 1 : 0);
            }), result});
    }
};
