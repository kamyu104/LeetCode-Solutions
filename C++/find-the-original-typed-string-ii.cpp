// Time:  O(n + k^2)
// Space: O(n + k)

// dp, prefix sum
class Solution {
public:
    int possibleStringCount(string word, int k) {
        static const int MOD = 1e9 + 7;

        vector<int> cnt = {0};
        for (int i = 0; i < size(word); ++i) {
            ++cnt.back();
            if (i + 1 == size(word) || word[i + 1] != word[i]) {
                cnt.emplace_back(0);
            }
        }
        cnt.pop_back();
        int result = accumulate(cbegin(cnt), cend(cnt), 1ll, [](const auto& accu, const auto& x) {
            return (accu * x) % MOD;
        });
        if (k <= size(cnt)) {
            return result;
        }
        vector<int> dp(k - size(cnt));
        dp[0] = 1;
        for (const auto& l : cnt) {
            for (int i = 0; i + 1 < size(dp); ++i) {
                dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
            }
            for (int i = size(dp) - 1; i >= l; --i) {
                dp[i] = ((dp[i] - dp[i - l]) % MOD + MOD) % MOD;
            }
        }
        return ((result - accumulate(cbegin(dp), cend(dp), 0, [](const auto& accu, const auto& x) {
            return (accu + x) % MOD;
        })) % MOD + MOD) % MOD;
    }
};
