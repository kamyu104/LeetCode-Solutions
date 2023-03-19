// Time:  O(n)
// Space: O(n)

// combinatorics, dp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        const auto& count = [&](int x) {
            int y = x;
            for (; cnt.count(y - k); y -= k);
            vector<int> dp = {1, 0};  // dp[0]: count without i, dp[1]: count with i
            for (int i = y; i <= x; i += k) {
                dp = {dp[0] + dp[1], dp[0] * ((1 << cnt[i]) - 1)};
            }
            return dp[0] + dp[1];
        };

        int result = 1;
        for (const auto& [i, _] : cnt) {
            if (!cnt.count(i + k)) {
                result *= count(i);
            }
        }
        return result - 1;
    }
};
