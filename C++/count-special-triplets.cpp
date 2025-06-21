// Time:  O(n)
// Space: O(n)

// dp
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        int result = 0;
        vector<unordered_map<int, int>> dp(2);
        for (const auto& x : nums) {
            if (x % 2 == 0 && dp[1].count(x / 2)) {
                result = (result + dp[1][x / 2]) % MOD;
            }
            if (dp[0].count(2 * x)) {
                dp[1][x] = (dp[1][x] + dp[0][2 * x]) % MOD;
            }
            dp[0][x] = (dp[0][x] + 1) % MOD;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// freq table
class Solution2 {
public:
    int specialTriplets(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        unordered_map<int, int> right;
        for (const auto& x : nums) {
            ++right[x];
        }
        int result = 0;
        unordered_map<int, int> left;
        for (const auto& x : nums) {
            --right[x];
            if (!right[x]) {
                right.erase(x);
            }
            if (left.count(2 * x) && right.count(2 * x)) {
                result = (result + static_cast<int64_t>(left[2 * x]) * right[2 * x]) % MOD;
            }
            ++left[x];
        }
        return result;
    }
};
