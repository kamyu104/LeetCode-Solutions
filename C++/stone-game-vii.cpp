// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        vector<int> prefix(1);
        for (const auto& stone : stones) {
            prefix.emplace_back(prefix.back() + stone);
        }
        const auto& score = [&prefix](int i, int j) {
            return prefix[j + 1] - prefix[i];
        };
        vector<vector<int>> dp(size(stones) , vector<int>(size(stones)));
        for (int i = size(stones) - 1; i >= 0; --i) {
            for (int j = i + 1; j < size(stones); ++j) {
                dp[i][j] = max(score(i + 1, j) - dp[i + 1][j],
                               score(i, j - 1) - dp[i][j - 1]);
            }
        }
        return dp[0][size(stones) - 1];
    }
};
