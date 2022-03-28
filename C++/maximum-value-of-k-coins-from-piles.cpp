// Time:  O(min(n * k^2, m * k)), m = sum(len(pile) for pile in piles)
// Space: O(k)

// dp
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(1);
        for (const auto& pile : piles) {
            vector<int> new_dp(min(static_cast<int>(size(dp) + size(pile)), k + 1));
            for (int i = 0; i < size(dp); ++i) {
                for (int j = 0, curr = 0; j <= min(k - i, static_cast<int>(size(pile))); ++j) {
                    new_dp[i + j] = max(new_dp[i + j], dp[i] + curr);
                    curr += j < size(pile) ? pile[j] : 0;
                }
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};
