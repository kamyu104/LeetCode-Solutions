// Time:  O(S * T)
// Space: O(S)

class Solution {
public:
    string minWindow(string S, string T) {
        vector<vector<int>> dp(2, vector<int>(S.length(), -1));
        for (int j = 0; j < S.length(); ++j) {
            if (S[j] == T[0]) {
                dp[0][j] = j;
            }
        }
                
        for (int i = 1; i < T.length(); ++i) {
            int prev = -1;
            dp[i % 2] = vector<int>(S.length(), -1);
            for (int j = 0; j < S.length(); ++j) {
                if (prev != -1 && S[j] == T[i]) {
                    dp[i % 2][j] = prev;
                }
                if (dp[(i - 1) % 2][j] != -1) {
                    prev = dp[(i - 1) % 2][j];
                }
            }
        }

        int start = 0, end = S.length();
        for (int j = 0; j < S.length(); ++j) {
            int i = dp[(T.length() - 1) % 2][j];
            if (i >= 0 && j - i < end - start) {
                tie(start, end) = make_pair(i, j);
            }
        }
        return end < S.length() ? S.substr(start, end - start + 1) : "";
    }
};
