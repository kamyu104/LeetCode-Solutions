// Time:  O(mlogm + nlogn + m * n)
// Space: O(m * n)

// sort, dp, prefix sum, mono deque
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        static const int64_t INF = numeric_limits<int64_t>::max();
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));
        vector<vector<int64_t>> dp(size(factory) + 1, vector<int64_t>(size(robot), INF));  // dp[i][j]: min of factory[:i+1] and robot[:j]
        for (int i = 0; i < size(factory); ++i) {
            int64_t prefix = 0;
            deque<pair<int64_t, int>> dq = {{0, -1}};
            for (int j = 0; j < size(robot); ++j) {
                prefix += abs(robot[j] - factory[i][0]);
                if (j - dq.back().second == factory[i][1] + 1) {
                    dq.pop_back();
                }
                while (!empty(dq) && dq.front().first >= (dp[i][j] != INF ? dp[i][j] - prefix : INF)) {
                    dq.pop_front();
                }
                dq.emplace_front((dp[i][j] != INF ? dp[i][j] - prefix : INF), j);
                dp[i + 1][j] = dq.back().first != INF ? dq.back().first + prefix : INF;
            }
        }
        return dp.back().back();
    }
};
