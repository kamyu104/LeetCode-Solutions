// Time:  ctor:    O(r^2)
//        runtime: O(r)
// Space: O(r^2)

// dp, combinatorics
const auto& init = [](int k) {
    vector<vector<int64_t>> dp(k + 1, vector<int64_t>(k + 1));
    for (int i = 0; i < size(dp); ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp;
};

static const int MAX_K = 50;
const auto& DP = init(MAX_K);
class Solution {
public:
    long long nthSmallest(long long n, int k) {
        int64_t result = 0;
        for (int i = MAX_K - 1; i >= 0; --i) {
            if (n <= DP[i][k]) {
                continue;
            }
            n -= DP[i][k];
            result |= 1ll << i;
            if (--k == 0) {
                break;
            }
        }
        return result;
    }
};
