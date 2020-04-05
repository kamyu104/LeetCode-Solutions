// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(3, numeric_limits<int>::min());
        dp[stoneValue.size() % 3] = 0;
        for (int i = stoneValue.size() - 1; i >= 0; --i) {
            int max_dp = numeric_limits<int>::min();
            for (int j = 0, curr = 0; j < 3 && i + j < stoneValue.size(); ++j) {
                curr += stoneValue[i + j];
                max_dp = max(max_dp, curr - dp[(i + j + 1) % 3]);
            }
            dp[i % 3] = max_dp;
        }
        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob"); 
    }
};
