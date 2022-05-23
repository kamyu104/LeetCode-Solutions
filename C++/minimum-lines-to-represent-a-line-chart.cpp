// Time:  O(nlogn)
// Space: O(1)

// sort, math, gcd
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int result =0;
        sort(begin(stockPrices), end(stockPrices));
        vector<int> prev;
        for (int i = 1; i < size(stockPrices); ++i) {
            const int dy = stockPrices[i][1] - stockPrices[i - 1][1];
            const int dx = stockPrices[i][0] - stockPrices[i - 1][0];
            const int g = gcd(dy, dx);
            if (empty(prev) || prev != vector<int>({dy / g, dx / g})) {
                prev = {dy / g, dx / g};
                ++result;
            }
        }
        return result;
    }
};
