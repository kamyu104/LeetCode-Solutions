// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            const int n = prices.size();

            if(n < 2)
                return 0;

            // Greedy Algorithm
            int ans = 0;
            for(int i = 1, valley = prices[0]; i < n; ++i) {
                ans = max(ans, prices[i] - valley);
                valley = min(valley, prices[i]);
            }

            return ans;
        }
};
