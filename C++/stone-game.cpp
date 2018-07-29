// Time:  O(n^2)
// Space: O(n)

// The solution is the same as https://leetcode.com/problems/predict-the-winner/description/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        if (piles.size() % 2 == 0 || piles.size() == 1) {
            return true;
        }

        vector<int> dp(piles.size());
        for (int i = piles.size() - 1; i >= 0; --i) {
            dp[i] = piles[i];
            for (int j = i + 1; j < piles.size(); ++j) {
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        
        return dp.back() >= 0;
    }
};

