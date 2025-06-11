// Time:  O(n * k)
// Space: O(k)

// dp
class Solution {
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
