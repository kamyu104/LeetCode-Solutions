// Time:  O(mlogm + nlogn + m * n)
// Space: O(n)

// sort, dp, prefix sum, mono deque
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        static const int64_t INF = numeric_limits<int64_t>::max();
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));
        vector<int64_t> dp(size(robot), INF);  // dp[j]: min of factory[:i+1] and robot[:j]
        for (int i = 0; i < size(factory); ++i) {
            int64_t prefix = 0;
            deque<pair<int64_t, int>> dq = {{0, -1}};
            vector<int64_t> new_dp(size(robot), INF);
            for (int j = 0; j < size(robot); ++j) {
                prefix += abs(robot[j] - factory[i][0]);
                if (j - dq.back().second == factory[i][1] + 1) {
                    dq.pop_back();
                }
                while (!empty(dq) && dq.front().first >= (dp[j] != INF ? dp[j] - prefix : INF)) {
                    dq.pop_front();
                }
                dq.emplace_front((dp[j] != INF ? dp[j] - prefix : INF), j);
                new_dp[j] = dq.back().first != INF ? dq.back().first + prefix : INF;
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};
