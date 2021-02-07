// Time:  O(nlogn + n * k)
// Space: O(n * k)

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });
        vector<int> prev(size(events));
        for (int i = 0; i < size(events); ++i) {
            prev[i] = distance(cbegin(events),
                               std::prev(lower_bound(cbegin(events), cend(events), events[i],
                                         [](const auto& a, const auto& b) {
                                             return a[1] < b[0];
                                         })));
        }
        vector<vector<int>> dp(size(events) + 1, vector<int>(k + 1));
        for (int i = 1; i <= size(events); ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[prev[i - 1] + 1][j - 1] + events[i - 1][2]});
            }
        }
        return dp[size(events)][k];
    }
};
