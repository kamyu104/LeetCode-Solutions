// Time:  O(m * n)
// Space: O(m * n)

// dp, mono deque
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        static const int64_t INF = numeric_limits<int64_t>::max();
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));
        vector<vector<int64_t>> dp(size(robot), vector<int64_t>(size(factory) + 1, INF));  // dp[i][j]: min of robot[:i+1] and factory[:j]
        for (int j = 0; j < size(factory); ++j) {
            int64_t prefix = 0;
            deque<pair<int64_t, int>> dq = {{0, -1}};
            for (int i = 0; i < size(robot); ++i) {
                prefix += abs(robot[i] - factory[j][0]);
                if (i - dq.back().second == factory[j][1] + 1) {
                    dq.pop_back();
                }
                while (!empty(dq) && dq.front().first >= (dp[i][j] != INF ? dp[i][j] - prefix : INF)) {
                    dq.pop_front();
                }
                dq.emplace_front((dp[i][j] != INF ? dp[i][j] - prefix : INF), i);
                dp[i][j + 1] = dq.back().first != INF ? dq.back().first + prefix : INF;
            }
        }
        return dp.back().back();
    }
};
