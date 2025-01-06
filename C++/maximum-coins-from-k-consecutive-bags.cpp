// Time:  O(nlogn)
// Space: O(1)

// sort, two pointers, sliding window
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        const auto& max_amount = [&]() {
            int64_t result = 0, curr = 0;
            sort(begin(coins), end(coins));
            for (int right = 0, left = 0; right < size(coins); ++right) {
                curr += static_cast<int64_t>(coins[right][1] - coins[right][0] + 1) * coins[right][2];
                for (; coins[right][1] - coins[left][1] + 1 > k; ++left) {
                    curr -= static_cast<int64_t>(coins[left][1] - coins[left][0] + 1) * coins[left][2];
                }
                result = max(result, curr - static_cast<int64_t>(max((coins[right][1] - coins[left][0] + 1) - k, 0)) * coins[left][2]);
            }
            return result;
        };

        int64_t result = max_amount();
        for (int i = 0; i < size(coins); ++i) {
            tie(coins[i][0], coins[i][1]) = pair(-coins[i][1], -coins[i][0]);
        }
        result = max(result, max_amount());
        return result;
    }
};
