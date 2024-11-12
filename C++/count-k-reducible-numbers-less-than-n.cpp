// Time:  O(n^2)
// Space: O(n)

// dp
vector<int> cnt = {0, 0};
class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        static const int MOD = 1e9 + 7;

        while (size(s) >= size(cnt)) {  // cached
            cnt.emplace_back(cnt[__builtin_popcount(size(cnt))] + 1);
        }
        vector<int> dp(size(s) + 1);
        for (int i = 0, curr = 0; i < size(s); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
            }
            if (s[i] != '1') {
                continue;
            }
            dp[curr] = (dp[curr] + 1) % MOD;
            ++curr;
        }
        int result = 0;
        for (int i = 1; i <= size(s); ++i) {
            if (cnt[i] < k) {
                result = (result + dp[i]) % MOD;
            }
        }
        return result;
    }
};
