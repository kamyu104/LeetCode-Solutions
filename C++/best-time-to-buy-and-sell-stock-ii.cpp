// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
             result += max(0, prices[i] - prices[i - 1]);
        }
        return result;
    }
};
