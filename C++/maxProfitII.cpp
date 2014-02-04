// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            const int n = prices.size();
            int ans = 0;

            for(int i = 1; i < n; ++i) {
                int diff = prices[i] - prices[i - 1];
                if(diff > 0)
                    ans += diff;
            }

            return ans;
        }
};
