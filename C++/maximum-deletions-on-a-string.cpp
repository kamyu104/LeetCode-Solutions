// Time:  O(n^2)
// Space: O(n)

// dp, lps algorithm
class Solution {
public:
    int deleteString(string s) {
        if (all_of(cbegin(s), cend(s), [&](const auto& x) { return x == s[0]; })) {
            return size(s);
        }
        
        const auto& longest_prefix_suffix = [&](int i) {
            vector<int> lps(size(s) - i);
            for (int j = 1, l = 0; j < size(lps); ++j) {
                while (l != 0 && s[i + l] != s[i + j]) {
                    l = lps[l - 1];
                }
                if (s[i + l] == s[i + j]) {
                    ++l;
                }
                lps[j] = l;
            }
            return lps;
        };

        vector<int> dp(size(s), 1);  // dp[i]: max operation count of s[i:]
        for (int i = size(s) - 2; i >= 0; --i) {
            const auto& lps = longest_prefix_suffix(i);  // lps[j]: longest prefix suffix length of s[i:j+1]                
            for (int j = 1; j < size(lps); j += 2) {
                if (2 * lps[j] == j + 1) {
                    dp[i] = max(dp[i], dp[i + lps[j]] + 1);
                }
            }
        }
        return dp[0];
    }
};


// Time:  O(n^2)
// Space: O(n^2)
// dp
class Solution2 {
public:
    int deleteString(string s) {
        if (all_of(cbegin(s), cend(s), [&](const auto& x) { return x == s[0]; })) {
            return size(s);
        }
        vector<vector<int>> dp(size(s) + 1, vector<int>(size(s) + 1));  // dp[i][j]: max prefix length of s[i:] and s[j:]
        vector<int> dp2(size(s), 1);  // dp2[i]: max operation count of s[i:]
        for (int i = size(s) - 2; i >= 0; --i) {
            for (int j = i + 1; j < size(s); ++j) {
                if (s[j] == s[i]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                }
                if (dp[i][j] >= j - i) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        return dp2[0];
    }
};
