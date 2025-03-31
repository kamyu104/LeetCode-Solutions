// Time:  O(n * m)
// Space: O(n + m)

// manacher's algorithm, dp
class Solution {
public:
    int longestPalindrome(string s, string t) {
        const auto& manacher = [](const string& s) {
            const auto& preProcess = [](const string& s) {
                if (empty(s)) {
                    return string("^$");
                }
                string ret = "^";
                for (int i = 0; i < size(s); ++i) {
                    ret += "#" + s.substr(i, 1);
                }
                ret += "#$";
                return ret;
            };

            string T = preProcess(s);
            const int n = size(T);
            vector<int> P(n);
            int C = 0, R = 0;
            for (int i = 1; i < n - 1; ++i) {
                int i_mirror = 2 * C - i;
                P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
                while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                    ++P[i];
                }
                if (i + P[i] > R) {
                    C = i;
                    R = i + P[i];
                }
            }
            return P;
        };

        const auto& longest_palindrome = [&](const auto &s) {
            vector<int> result(size(s) + 1);
            const auto& P = manacher(s);
            for (int i = 1; i + 1 < size(P); ++i) {
                result[(i - P[i]) / 2] = P[i];
            } 
            return result;
        };

        reverse(begin(t), end(t));
        const auto& p1 = longest_palindrome(s);
        const auto& p2 = longest_palindrome(t);
        int result = 0;
        vector<vector<int>> dp(size(s) + 1, vector<int>(size(t) + 1));
        for (int i = 0; i < size(s); ++i) {
            for (int j = 0; j < size(t); ++j) {
                dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] + 2 : 0;
                result = max(result, dp[i + 1][j + 1] + max(p1[i + (s[i] == t[j] ? 1 : 0)] , p2[j + (s[i] == t[j] ? 1 : 0)]));
            }
        }
        return result;                
    }
};
