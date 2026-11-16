// Time:  O(n)
// Space: O(1)

// string, dp
class Solution {
public:
    long long countValidSubstrings(string s) {
        int64_t result = 0;
        vector<int> dp(3, -1);
        for (const auto& [i, x] : s | views::enumerate) {
            if (x == 'a') {
                dp[0] = i;
            } else if (x == 'b') {
                dp[1] = dp[0];
            } else if (x == 'c') {
                dp[2] = dp[1];
            }
            result += i - dp[2];
        }
        return result;
    }
};
