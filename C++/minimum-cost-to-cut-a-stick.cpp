// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> sorted_cuts(cbegin(cuts), cend(cuts));
        sorted_cuts.emplace_back(0);
        sorted_cuts.emplace_back(n);
        sort(begin(sorted_cuts), end(sorted_cuts));

        vector<vector<int>> dp(sorted_cuts.size(), vector<int>(sorted_cuts.size()));
        for (int l = 2; l < sorted_cuts.size(); ++l) {
            for (int i = 0; i + l < sorted_cuts.size(); ++i) {
                dp[i][i + l]  = numeric_limits<int>::max();
                for (int j = i + 1; j < i + l; ++j) {
                    dp[i][i + l]  = min(dp[i][i + l], dp[i][j] + dp[j][i + l] +
                                    sorted_cuts[i + l] - sorted_cuts[i]);
                }
            }
        }
        return dp[0][sorted_cuts.size() - 1];
    }
};
