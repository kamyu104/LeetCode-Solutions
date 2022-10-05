// Time:  O(n^2)
// Space: O(n)

// dp
class Solution {
public:
    int deleteString(string s) {
        if (all_of(cbegin(s), cend(s), [&](const auto& x) { return x == s[0]; })) {
            return size(s);
        }
        vector<vector<int>> dp(2, vector<int>(size(s) + 1));  // dp[i%2][j]: max prefix length of s[i:] and s[j:]
        vector<int> dp2(size(s), 1);  // dp2[i]: max operation count of s[i:]
        for (int i = size(s) - 2; i >= 0; --i) {
            for (int j = i + 1; j < size(s); ++j) {
                dp[i % 2][j] = (s[j] == s[i]) ? dp[(i + 1) % 2][j + 1] + 1 : 0;
                if (dp[i % 2][j] >= j - i) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        return dp2[0];
    }
};

// Time:  O(n^2)
// Space: O(n)
// dp, kmp algorithm
class Solution2 {
public:
    int deleteString(string s) {
        if (all_of(cbegin(s), cend(s), [&](const auto& x) { return x == s[0]; })) {
            return size(s);
        }
        
        const auto& getPrefix = [](const auto& pattern, int start) {  // Time: O(n), Space: O(n)
            vector<int> prefix(size(pattern) - start, -1);
            int j = -1;
            for (int i = 1; start + i < size(pattern); ++i) {
                while (j != -1 && pattern[start + j + 1] != pattern[start + i]) {
                    j = prefix[j];
                }
                if (pattern[start + j + 1] == pattern[start + i]) {
                    ++j;
                }
                prefix[i] = j;
            }
            return prefix;
        };

        vector<int> dp(size(s), 1);  // dp[i]: max operation count of s[i:]
        for (int i = size(s) - 2; i >= 0; --i) {
            const auto& prefix = getPrefix(s, i);  // prefix[j] + 1: longest prefix suffix length of s[i:j+1]                
            for (int j = 1; j < size(prefix); j += 2) {
                if (2 * (prefix[j] + 1) == j + 1) {
                    dp[i] = max(dp[i], dp[i + (prefix[j] + 1)] + 1);
                }
            }
        }
        return dp[0];
    }
};
