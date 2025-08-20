// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int64_t result = 0, curr = 0;
        for (int i = 0; i < size(prices); ++i) {
            curr += (i < k) ? prices[i] * (i < k / 2 ? 0 : 1) : prices[i] * strategy[i];
            result += prices[i] * strategy[i];
        }
        result = max(result, curr);
        for (int i = k; i < size(prices); ++i) {
            curr += (prices[i - k] * strategy[i - k]) + (prices[i] - prices[i - k / 2]) - (prices[i] * strategy[i]);
            result = max(result, curr);
        }
        return result;
    }
};
