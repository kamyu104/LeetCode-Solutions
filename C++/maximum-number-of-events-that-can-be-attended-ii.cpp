// Time:  O(nlogn + n * k)
// Space: O(n * k)

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });
        vector<int> prv(size(events));
        for (int i = 0; i < size(events); ++i) {
            prv[i] = distance(cbegin(events),
                              prev(lower_bound(cbegin(events), cend(events), events[i],
                                   [](const auto& a, const auto& b) {
                                       return a[1] < b[0];
                                   })));
        }
        vector<vector<int>> dp(size(events) + 1, vector<int>(k + 1));
        for (int i = 1; i <= size(events); ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[prv[i - 1] + 1][j - 1] + events[i - 1][2]);
            }
        }
        return dp[size(events)][k];
    }
};

// Time:  O(nlogn + n * k)
// Space: O(n * k)
class Solution2 {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));
        vector<int> sorted_starts;
        for (const auto& event : events) {
            sorted_starts.emplace_back(event[0]);
        }
        vector<int> nxt(size(events));
        for (int i = 0; i < size(events); ++i) {
            nxt[i] = distance(cbegin(sorted_starts),
                              prev(upper_bound(cbegin(sorted_starts), cend(sorted_starts), events[i][1])));
        }
        vector<vector<int>> dp(size(events) + 1, vector<int>(k + 1));
        for (int i = size(events) - 1; i >= 0; --i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i + 1][j], dp[nxt[i] + 1][j - 1] + events[i][2]);
            }
        }
        return dp[0][k];
    }
};
