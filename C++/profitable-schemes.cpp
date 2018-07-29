// Time:  O(n * p * g)
// Space: O(p * g)

class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        static const int M = 1000000007;
        vector<vector<int>> dp(P + 1, vector<int>(G + 1));
        dp[0][0] = 1;
        int result = 0;
        for (int k = 0; k < group.size(); ++k) {
            int g = group[k], p = profit[k];
            for (int i = P; i >= 0; --i)
                for (int j = G - g; j >= 0; --j)
                    dp[min(i + p, P)][j + g] = (dp[min(i + p, P)][j + g] + dp[i][j]) % M;
        }
        for (const auto& p : dp[P]) {
            result = (result + p) % M;
        }
        return result;
    }
};
