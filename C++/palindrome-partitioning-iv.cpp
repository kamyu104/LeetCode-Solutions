// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    bool checkPartitioning(string s) {
        const auto& P = manacher(s);
        vector<int> prefix, suffix;
        for (int i = 2; i < size(P) - 2; ++i) {
            if (i - 1 - P[i] == 0) {
                prefix.emplace_back(i);
            }
            if (i + 1 + P[i] == size(P) - 1) {
                suffix.emplace_back(i);
            }
        }
        for (const auto& i : prefix) {
            for (const auto& j : suffix) {
                int left = i + 1 + P[i], right = j - 1 - P[j];
                if (left > right) {
                    continue;
                }
                int mid = left + (right - left) / 2;
                if (P[mid] >= mid - left) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    vector<int> manacher(const string& s) {
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
    }
        
    string preProcess(const string& s) {
        if (empty(s)) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < size(s); ++i) {
            ret += "#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
};

// Time:  O(n^2)
// Space: O(n^2)
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
            if (!dp[0][i - 1]) {
                continue;
            }
            for (int j = i + 1; j < size(s); ++j) {
                if (!dp[j][size(s) - 1]) {
                    continue;
                }
                if (dp[i][j - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
};
