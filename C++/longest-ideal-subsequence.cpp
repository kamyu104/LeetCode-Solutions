// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26);
        for (const auto& c : s) {
            const int x = c - 'a';
            dp[x] = *max_element(cbegin(dp) + max(x - k, 0), cbegin(dp) + min(x + k + 1, 26)) + 1;
        }
        return *max_element(cbegin(dp), cend(dp));
    }
};
