// Time:  O(nlogk)
// Space: O(logk)

class Solution {
public:
    int numberOfArrays(string s, int k) {
        static const int MOD = 1e9 + 7;
        int klen = to_string(k).length();
        vector<int> dp(klen + 1);
        dp[s.length() % dp.size()] = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            dp[i % dp.size()] = 0;
            if (s[i] == '0') {
                continue;
            }
            for (uint64_t j = i, curr = 0; j < min(uint64_t(i + klen), s.length()); ++j) {
                curr = curr * 10 + s[j] - '0';
                if (curr > k) {
                    break;
                }
                dp[i % dp.size()] = (dp[i % dp.size()] + dp[(j + 1) % dp.size()]) % MOD;
            }
        }
        return dp[0];
    }
};
