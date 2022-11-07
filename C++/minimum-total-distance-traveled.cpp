// Time:  O(mlogm + nlogn + m * n)
// Space: O(n)

// sort, dp, prefix sum, mono deque
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        static const int64_t INF = numeric_limits<int64_t>::max();
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));
        vector<int64_t> dp(size(robot) + 1, INF);  // dp[j] at i: min of factory[:i+1] and robot[:j]
        dp[0] = 0;
        for (int i = 0; i < size(factory); ++i) {
            int64_t prefix = 0;
            deque<pair<int64_t, int>> dq = {{dp[0] - prefix, 0}};  // pattern of min in the sliding window with size (limit+1)
            for (int j = 1; j <= size(robot); ++j) {
                prefix += abs(robot[j - 1] - factory[i][0]);
                if (j - dq.front().second == factory[i][1] + 1) {
                    dq.pop_front();
                }
                while (!empty(dq) && dq.back().first >= (dp[j] != INF ? dp[j] - prefix : INF)) {
                    dq.pop_back();
                }
                dq.emplace_back((dp[j] != INF ? dp[j] - prefix : INF), j);
                dp[j] = dq.front().first != INF ? dq.front().first + prefix : INF;
            }
        }
        return dp.back();
    }
};

// Time:  O(mlogm + nlogn + m * n * l), l is the max limit
// Space: O(n)
// sort, dp
class Solution2 {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        static const int64_t INF = numeric_limits<int64_t>::max();
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));
        vector<int64_t> dp(size(robot) + 1, INF);  // dp[j] at i: min of factory[:i+1] and robot[:j]
        dp[0] = 0;
        for (int i = 0; i < size(factory); ++i) {
            for (int j = size(robot); j >= 1; --j) {
                int64_t curr = 0;
                for (int k = 0; k <= min(factory[i][1], j); ++k) {
                    dp[j] = min(dp[j], dp[j - k] != INF ? dp[j - k] + curr : INF);
                    if ((j - 1) - k >= 0) {
                        curr += abs(robot[(j - 1) - k] - factory[i][0]);
                    }
                }
            }
        }
        return dp.back();
    }
};
