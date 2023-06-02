// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        const auto& min_idx = [&](int exclude) {
            int j = -1;
            for (int i = 0; i < size(prices); ++i) {
                if (i != exclude && (j == -1 || prices[j] > prices[i])) {
                    j = i;
                }
            }
            return j;
        };
    
        const auto& i = min_idx(-1);
        const auto& j = min_idx(i);
        return prices[i] + prices[j] <= money ? money - (prices[i] + prices[j]) : money;
    }
};
