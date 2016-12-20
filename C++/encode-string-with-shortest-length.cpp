// Time:  O(n^3) on average
// Space: O(n^2)

class Solution {
public:
    string encode(string s) {
        vector<vector<string>> dp(s.length(), vector<string>(s.length()));
        for (int len = 1; len <= s.length(); ++len) {
            for (int i = 0; i + len - 1 < s.length(); ++i) {
                int j = i + len - 1;
                dp[i][j] = s.substr(i, len);
                for (int k = i; k < j; ++k) {
                    if (dp[i][k].length() + dp[k + 1][j].length() < dp[i][j].length()) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                    }
                }
                string encoded_string = encode_substr(dp, s, i, j);
                if (encoded_string.length() < dp[i][j].length()) {
                    dp[i][j] = encoded_string;
                }
            }
        }
        return dp[0][s.length() - 1];
    }

private:
    string encode_substr(const vector<vector<string>>& dp, const string& s, int i, int j) {
        string temp = s.substr(i, j - i + 1);
        auto pos = (temp + temp).find(temp, 1);  // O(n) on average
        if (pos >= temp.length()) {
            return temp;
        }
        return to_string(temp.length() / pos) + '[' + dp[i][i + pos - 1] + ']';
    }
};
