// Time:  O(m * n * k) = O(m * n)
// Space: O(min(m, n) * k) = O(min(m, n))

// dp
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        static const int K = 2;
        const int mn = min(size(coins), size(coins[0]));
        const int mx = max(size(coins), size(coins[0]));
        const function<int (int, int)> get1 = [&](int i, int j) {
            return coins[i][j];
        };
        const function<int (int, int)> get2 = [&](int i, int j) {
            return coins[j][i];
        };
        const function<int (int, int)>& get = size(coins) == mx ? get1 : get2;
        vector<vector<int>> dp(mn, vector<int>(K + 1, numeric_limits<int>::min()));
        for (int i = 0; i < mx; ++i) {
            vector<vector<int>> new_dp(mn, vector<int>(K + 1, numeric_limits<int>::min()));
            for (int j = 0; j < mn; ++j) {
                for (int k = 0; k <= K; ++k) {
                    if (i == 0 && j == 0) {
                        new_dp[j][k] = k - 1 >= 0 ? max(get(i, j), 0) : get(i, j);
                        continue;
                    }
                    if (i - 1 >= 0) {
                        new_dp[j][k] = max(new_dp[j][k], dp[j][k] + get(i, j));
                        if (k - 1 >= 0) {
                            new_dp[j][k] = max(new_dp[j][k], dp[j][k - 1]);
                        }
                    }
                    if (j - 1 >= 0) {
                        new_dp[j][k] = max(new_dp[j][k], new_dp[j - 1][k] + get(i, j));
                        if (k - 1 >= 0) {
                            new_dp[j][k] = max(new_dp[j][k], new_dp[j - 1][k - 1]);
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        return dp[mn - 1][K];
    }
};

// Time:  O(m * n * k) = O(m * n)
// Space: O(n * k) = O(n)
// dp
class Solution2 {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        static const int K = 2;
        vector<vector<int>> dp(size(coins[0]), vector<int>(K + 1, numeric_limits<int>::min()));
        for (int i = 0; i < size(coins); ++i) {
            vector<vector<int>> new_dp(size(coins[0]), vector<int>(K + 1, numeric_limits<int>::min()));
            for (int j = 0; j < size(coins[0]); ++j) {
                for (int k = 0; k <= K; ++k) {
                    if (i == 0 && j == 0) {
                        new_dp[j][k] = k - 1 >= 0 ? max(coins[i][j], 0) : coins[i][j];
                        continue;
                    }
                    if (i - 1 >= 0) {
                        new_dp[j][k] = max(new_dp[j][k], dp[j][k] + coins[i][j]);
                        if (k - 1 >= 0) {
                            new_dp[j][k] = max(new_dp[j][k], dp[j][k - 1]);
                        }
                    }
                    if (j - 1 >= 0) {
                        new_dp[j][k] = max(new_dp[j][k], new_dp[j - 1][k] + coins[i][j]);
                        if (k - 1 >= 0) {
                            new_dp[j][k] = max(new_dp[j][k], new_dp[j - 1][k - 1]);
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        return dp[size(coins[0]) - 1][K];
    }
};
