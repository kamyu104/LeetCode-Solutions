// Time:  O(n * k)
// Space: O(k)

// dp
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        static const int64_t NEG_INF = numeric_limits<int64_t>::min();

        vector<int64_t> dp(size(prices) + 1);
        int64_t result = 0;
        for (int i = 0; i < k; ++i) {
            vector<int64_t> new_dp(size(prices) + 1, NEG_INF);
            int64_t x = NEG_INF, y = NEG_INF;
            for (int j = i; j < size(prices); ++j) {
                x = max(x, dp[j] - prices[j]);
                y = max(y, dp[j] + prices[j]);
                new_dp[j + 1] = max({new_dp[j], x + prices[j], y - prices[j]});
            }
            dp = move(new_dp);
            result = max(result, dp.back());
        }
        return result;
    }
};

// Time:  O(n * k)
// Space: O(k)
// dp
class Solution2 {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        static const int64_t NEG_INF = numeric_limits<int64_t>::min();

        vector<int64_t> bought(k, NEG_INF);
        vector<int64_t> sold(k, NEG_INF);
        vector<int64_t> result(k + 1);
        for (const auto& x : prices) {
            for (int i = k - 1; i >= 0; --i) {
                if (bought[i] != NEG_INF) {
                    result[i + 1] = max(result[i + 1], bought[i] + x);
                }
                if (sold[i] != NEG_INF) {
                    result[i + 1] = max(result[i + 1], sold[i] - x);
                }
                if (result[i] != NEG_INF) {
                    bought[i] = max(bought[i], result[i] - x);
                    sold[i] = max(sold[i], result[i] + x);
                }
            }
        }
        return result.back();
    }
};

// Time:  O(n * k)
// Space: O(k)
// dp
class Solution3 {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        static const int64_t NEG_INF = numeric_limits<int64_t>::min();

        vector<int64_t> bought(k, NEG_INF);
        vector<int64_t> sold(k, NEG_INF);
        vector<int64_t> result(k + 1, NEG_INF);
        result[0] = 0;
        for (const auto& x : prices) {
            for (int i = k - 1; i >= 0; --i) {
                if (bought[i] != NEG_INF) {
                    result[i + 1] = max(result[i + 1], bought[i] + x);
                }
                if (sold[i] != NEG_INF) {
                    result[i + 1] = max(result[i + 1], sold[i] - x);
                }
                if (result[i] != NEG_INF) {
                    bought[i] = max(bought[i], result[i] - x);
                    sold[i] = max(sold[i], result[i] + x);
                }
            }
        }
        return ranges::max(result);
    }
};
