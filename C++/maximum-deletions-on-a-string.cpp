// Time:  O(n^2)
// Space: O(n)

// dp
class Solution {
public:
    int deleteString(string s) {
        if (all_of(cbegin(s), cend(s), [&](const auto& x) { return x == s[0]; })) {
            return size(s);
        }
        vector<vector<int>> dp2(2, vector<int>(size(s) + 1));  // dp2[i%2][j]: max prefix length of s[i:] and s[j:]
        vector<int> dp(size(s), 1);  // dp[i]: max operation count of s[i:]
        for (int i = size(s) - 2; i >= 0; --i) {
            for (int j = i + 1; j < size(s); ++j) {
                dp2[i % 2][j] = (s[j] == s[i]) ? dp2[(i + 1) % 2][j + 1] + 1 : 0;
                if (dp2[i % 2][j] >= j - i) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[0];
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

// Time:  O(n^2)
// Space: O(n)
// dp, rolling hash
class Solution3 {
public:
    int deleteString(string s) {
        static const int MOD = 1e9 + 7;
        static vector<int> P = {113, 109};
        if (all_of(cbegin(s), cend(s), [&](const auto& x) { return x == s[0]; })) {
            return size(s);
        }
        vector<vector<int64_t>> power(size(P), vector<int64_t>(1, 1));
        vector<vector<int64_t>> prefix(size(P), vector<int64_t>(1));
        const auto& hash = [&](int i, int j) {
            vector<int> h(size(P));
            for (int idx = 0; idx < size(P); ++idx) {
                h[idx] = ((prefix[idx][j + 1] - prefix[idx][i] * power[idx][j - i + 1]) % MOD + MOD) % MOD;
            }
            return h;
        };
        for (const auto& x : s) {
            for (int idx = 0; idx < size(P); ++idx) {
                power[idx].emplace_back(power[idx].back() * P[idx] % MOD);
                prefix[idx].emplace_back((prefix[idx].back() * P[idx] + (x - 'a')) % MOD);
            }
        }
        vector<int> dp(size(s), 1);  // dp[i]: max operation count of s[i:]
        for (int i = size(s) - 2; i >= 0; --i) {              
            for (int j = 1; j <= (size(s) - i) / 2 ; ++j) {
                if (hash(i, i + j - 1) == hash(i + j, i + 2 * j - 1)) {
                    dp[i] = max(dp[i], dp[i + j] + 1);
                }
            }
        }
        return dp[0];
    }
};
