// Time:  O(10 * 2^4 * logn)
// Space: O(2^3)

// dp
class Solution {
public:
    long long countNoZeroPairs(long long n) {
        vector<vector<vector<int64_t>>> dp(2, vector<vector<int64_t>>(2, vector<int64_t>(2)));  // dp[carry][a is finished][b is finished]
        dp[0][0][0] = 1;
        for (int start = 1; n; n /= 10) {
            const auto& d = n % 10;
            vector<vector<vector<int64_t>>> new_dp(2, vector<vector<int64_t>>(2, vector<int64_t>(2)));
            for (int c = 0; c < 2; ++c) {
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        if (!dp[c][i][j]) {
                            continue;
                        }
                        for (int x = start; x <= (!i ? 9 : 0); ++x) {
                            for (int nc = 0; nc < 2; ++nc) {
                                const auto& y = (d + nc * 10) - (c + x);
                                if (!(start <= y && y <= (!j ? 9 : 0))) {
                                    continue;
                                }
                                new_dp[nc][i || !x][j || !y] += dp[c][i][j];
                            }
                        }
                    }
                }
            }
            start = 0;
            dp = move(new_dp);
        }
        int64_t result = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result += dp[0][i][j];
            }
        }
        return result;
    }
};

// Time:  O(10^2 * 2^3 * logn)
// Space: O(2^3)
// dp
class Solution2 {
public:
    long long countNoZeroPairs(long long n) {
        vector<vector<vector<int64_t>>> dp(2, vector<vector<int64_t>>(2, vector<int64_t>(2)));  // dp[carry][a is finished][b is finished]
        dp[0][0][0] = 1;
        for (int start = 1; n; n /= 10) {
            const auto& d = n % 10;
            vector<vector<vector<int64_t>>> new_dp(2, vector<vector<int64_t>>(2, vector<int64_t>(2)));
            for (int c = 0; c < 2; ++c) {
                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        if (!dp[c][i][j]) {
                            continue;
                        }
                        for (int x = start; x <= (!i ? 9 : 0); ++x) {
                            for (int y = start; y <= (!j ? 9 : 0); ++y) {
                                if ((c + x + y) % 10 != d) {
                                    continue;
                                }
                                new_dp[(c + x + y) / 10][i || !x][j || !y] += dp[c][i][j];
                            }
                        }
                    }
                }
            }
            start = 0;
            dp = move(new_dp);
        }
        int64_t result = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                result += dp[0][i][j];
            }
        }
        return result;
    }
};
