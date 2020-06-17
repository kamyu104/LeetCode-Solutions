// Time:  O(m * n^2)
// Space: O(n)

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(begin(houses), end(houses));
        vector<int> prefix(houses.size() + 1);
        for (int i = 0; i < houses.size(); ++i) {
            prefix[i + 1] = prefix[i] + houses[i];
        }
        vector<int> dp(houses.size());
        for (int j = 0; j < houses.size(); ++j) {
            dp[j] = cost(prefix, 0, j);
        }
        for (int m = 1; m < k; ++m) {
            for (int j = houses.size() - 1; j >= 0; --j) {
                for (int i = m; i <= j; ++i) {
                    dp[j] = min(dp[j], dp[i - 1] + cost(prefix, i, j));
                }
            }
        }
        return dp.back();
    }

private:
    int cost(const vector<int>& prefix, int i, int j) {
        return (prefix[j + 1] - prefix[(i + j + 1) / 2]) -
               (prefix[(i + j) / 2 + 1] - prefix[i]);
    }
};
