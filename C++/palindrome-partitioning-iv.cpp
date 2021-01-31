// Time:  O(n)
// Space: O(n)

class Solution {
public:
    bool checkPartitioning(string s) {
        return modifiedManacher(s);
    }

private:
    bool modifiedManacher(const string& s) {
        string T = preProcess(s);
        const int n = T.length();
        vector<int> P(n);
        vector<bool> dp1(n);  // dp1[i]: s[:i] is a palindromic string
        vector<bool> dp2(n);  // dp2[i]: s[:i+1] is composed of 2 palindromic strings
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; ++i) {
            int i_mirror = 2 * C - i;
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                if (dp1[i - 1 - P[i]]) {
                    dp2[i + 1 + P[i]] = true;
                }
                ++P[i];
            }
            if (i + 1 + P[i] == n - 1 && dp2[i - 1 - P[i]]) {
                return true;
            }
            if (i - 1 - P[i] == 0) {
                dp1[i + 1 + P[i]] = true;
            }
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        return false;
    }
        
    string preProcess(const string& s) {
        if (s.empty()) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < s.length(); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution2 {
public:
    bool checkPartitioning(string s) {
        vector<vector<bool>> dp(size(s), vector<bool>(size(s)));
        for (int i = size(s) - 1; i >= 0; --i) {
            for (int j = i; j < size(s); ++j) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        for (int i = 1; i + 1 < size(s); ++i) {
            for (int j = i + 1; j < size(s); ++j) {
                if (dp[0][i - 1] && dp[i][j - 1] && dp[j][size(s) - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};
