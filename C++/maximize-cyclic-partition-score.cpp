// Time:  O(n * k)
// Space: O(k)

// dp
class Solution {
public:
    long long maximumScore(vector<int>& nums, int k) {
        const auto& best_time_to_buy_and_sell_stock_v = [&](int base) {
            static const int64_t NEG_INF = numeric_limits<int64_t>::min();

            vector<int64_t> dp(size(nums) + 1);
            int64_t result = 0;
            for (int i = 0; i < k; ++i) {
                vector<int64_t> new_dp(size(nums) + 1, NEG_INF);
                int64_t x = NEG_INF, y = NEG_INF;
                for (int j = i; j < size(nums); ++j) {
                    x = max(x, dp[j] - nums[(base + j) % size(nums)]);
                    y = max(y, dp[j] + nums[(base + j) % size(nums)]);
                    new_dp[j + 1] = max({new_dp[j], x + nums[(base + j) % size(nums)], y - nums[(base + j) % size(nums)]});
                }
                dp = move(new_dp);
                result = max(result, dp.back());
            }
            return result;
        };

        const int i = distance(cbegin(nums), min_element(cbegin(nums), cend(nums)));
        return max(best_time_to_buy_and_sell_stock_v(i), best_time_to_buy_and_sell_stock_v(i + 1));
    }
};
