// Time:  O(n^2 * k)
// Space: O(n * k)

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(k + 1, s.length()));
        dp[0][0] = 0;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j <= k; ++j) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
                int keep = 0, del = 0;
                for (int m = i; m <= s.length(); ++m) {
                    if (s[i - 1] == s[m - 1]) {
                        ++keep;
                    } else {
                        ++del;
                    }
                    if (j + del <= k) {
                        dp[m][j + del] = min(dp[m][j + del], dp[i - 1][j] + length(keep));
                    }
                }
            }
        }
        return dp[s.length()][k];
    }

private:
    int length(int cnt) {
        int l = ((cnt >= 2) ? 2 : 1);
        for (; cnt >= 10; cnt /= 10, ++l);
        return l;
    }
};
