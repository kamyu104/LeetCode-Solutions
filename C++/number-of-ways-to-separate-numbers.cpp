// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int numberOfCombinations(string num) {
        static const int MOD = 1e9 + 7;

        const auto& lcp = find_longest_common_prefix(num);
        vector<vector<int64_t>> dp(size(num), vector<int64_t>(size(num)));  // dp[i][l]: the count of numbers ending at num[i], where the length of the last number is l+1
        dp[0][0] = int(num[0] != '0');
        for (int i = 1; i < size(num); ++i) {
            dp[i][i] = dp[i - 1][i - 1];
            if (num[i] == '0') {
                continue;
            }
            for (int l = 1, accu = 0; i + l - 1 < size(num); ++l) {
                const int ni = i + l - 1;
                dp[ni][l - 1] = accu;  // accumulated count where the length of the second to last number ending at num[i-1] is shorter than the length of the last number ending at num[i+l-1]
                if (i - l < 0) {
                    continue;
                }
                if (num[i - l] != '0' && is_less_or_equal_to_with_same_length(num, lcp, i - l, i, l)) {
                    dp[ni][l - 1] = (dp[ni][l - 1] + dp[i - 1][l - 1]) % MOD;
                }
                accu = (accu + dp[i - 1][l - 1]) % MOD;
            }
        }
        return accumulate(cbegin(dp.back()), cend(dp.back()), 0,
                          [](const auto& a, const auto& b) {
                              return (a + b) % MOD;
                          });
    }

private:
    vector<vector<int64_t>> find_longest_common_prefix(const string& num) {
        vector<vector<int64_t>> lcp(size(num) + 1, vector<int64_t>(size(num) + 1));  // lcp[i][j]: longest length of the common prefix which starts at num[i], num[j]
        for (int i = size(lcp) - 2; i >= 0; --i) {
            for (int j = size(lcp[i]) - 2; j >= 0; --j) {
                if (num[i] == num[j]) {
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
                }
            }
        }
        return lcp;
    }

    bool is_less_or_equal_to_with_same_length(
        const string& num,
        const vector<vector<int64_t>>& lcp,
        int i, int j, int l) {
        return lcp[i][j] >= l || num[i + lcp[i][j]] < num[j + lcp[i][j]];
    }
};
