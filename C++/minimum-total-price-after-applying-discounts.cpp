// Time:  O(nlogn + mlogm)
// Space: O(1)

// sort, greedy
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(begin(prices), end(prices), greater<int>());
        sort(begin(discounts), end(discounts), greater<int>());
        int64_t total = accumulate(cbegin(prices), cend(prices), 0LL) * 100;
        for (int i = 0; i < min(size(prices), size(discounts)); ++i) {
            total -= prices[i] * discounts[i];
        }
        return total / 100.0;
    }
};
