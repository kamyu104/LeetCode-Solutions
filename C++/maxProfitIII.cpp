// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            const int n = prices.size();

            if(n < 2)
                return 0;

            vector<int> f(n, 0);
            vector<int> g(n, 0);

            for(int i = 1, valley = prices[0]; i < n; ++i) {
                f[i] = max(f[i - 1], prices[i] - valley);
                valley = min(valley, prices[i]);
            }

            for(int i = n - 2, peak = prices[n - 1]; i >= 0; --i) {
                g[i] = max(g[i + 1], peak - prices[i]);
                peak = max(peak, prices[i]);
            }

            int ans = 0;
            for(int i = 0; i < n; ++i) {
                ans = max(ans, f[i] + g[i]);
            }

            return ans;
        }
};
