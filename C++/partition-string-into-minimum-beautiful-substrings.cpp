// Time:  O(n^2)
// Space: O(n)

// dp
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        static const int INF = numeric_limits<int>::max();

        int max_pow_5 = 1;
        while (max_pow_5 * 5 <= (1 << size(s)) - 1) {
            max_pow_5 *= 5;
        }
        vector<int> dp(size(s) + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == '0') {
                continue;
            }
            int curr = 0;
            for (int j = i; j < size(s); ++j) {
                curr = curr * 2 + (s[j] - '0') ;
                if (max_pow_5 % curr == 0) {
                    if (dp[(i - 1) + 1] != INF) {
                        dp[j + 1] = min(dp[j + 1], dp[(i - 1) + 1] + 1);
                    }
                }
            }
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};


// Time:  O(n^2)
// Space: O(n)
// dp
class Solution2 {
public:
    int minimumBeautifulSubstrings(string s) {
        static const int INF = numeric_limits<int>::max();

        int max_pow_5 = 1;
        while (max_pow_5 * 5 <= (1 << size(s)) - 1) {
            max_pow_5 *= 5;
        }
        vector<int> dp(size(s) + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(s); ++i) {
            int curr = 0;
            for (int j = i; j >= 0; --j) {
                curr += (s[j] - '0') << (i - j);
                if (s[j] == '1' && max_pow_5 % curr == 0) {
                    if (dp[(j - 1) + 1] != INF) {
                        dp[i + 1] = min(dp[i + 1], dp[(j - 1) + 1] + 1);
                    }
                }
            }
        }
        return dp.back() != INF ? dp.back() : -1;
    }
};
