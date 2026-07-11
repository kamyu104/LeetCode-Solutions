// Time:  O(n * m * t)
// Space: O(n * m)

// dp, prefix sum
class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        static const int MOD = 1e9 + 7;

        vector<vector<int>> dp(size(word1) + 1, vector<int>(size(word2) + 1));
        dp[0][0] = 1;
        for (const auto& c : target) {
            vector<vector<int>> new_dp(size(word1) + 1, vector<int>(size(word2) + 1));
            vector<int> col(size(word2) + 1);
            for (int i = 0; i <= size(word1); ++i) {
                int row = 0;
                for (int j = 0; j <= size(word2); ++j) {
                    row = (row + dp[i][j]) % MOD;
                    if (j < size(word2) && word2[j] == c) {
                        new_dp[i][j + 1] = (new_dp[i][j + 1] + row) % MOD;
                    }
                    col[j] = (col[j] + dp[i][j]) % MOD;
                    if (i < size(word1) && word1[i] == c) {
                        new_dp[i + 1][j] = (new_dp[i + 1][j] + col[j]) % MOD;
                    }
                }
            }
            dp = move(new_dp);
        }
        int result = 0;
        for (int i = 1; i <= size(word1); ++i) {
            for (int j = 1; j <= size(word2); ++j) {
                result = (result + dp[i][j]) % MOD;
            }
        }
        return result;
    }
};
