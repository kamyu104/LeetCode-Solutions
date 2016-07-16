// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> pay(n + 1, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                pay[i][j] = numeric_limits<int>::max();
                for (int k = i; k <= j; ++k) {
                    pay[i][j] = min(pay[i][j], k + 1 + max(pay[i][k - 1], pay[k + 1][j]));
                }
            }
        }
        return pay[0][n - 1];
    }
};
