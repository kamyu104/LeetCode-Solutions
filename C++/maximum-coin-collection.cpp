// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    long long maxCoins(vector<int>& lane1, vector<int>& lane2) {
        int64_t NEG_INF = numeric_limits<int64_t>::min();
        int64_t result = NEG_INF, dp1 = NEG_INF, dp12 = NEG_INF, dp121 = NEG_INF;
        for (int i = 0; i < size(lane1); ++i) {
            dp1 = max(dp1, static_cast<int64_t>(0)) + lane1[i];
            dp12 = max(max(dp12, static_cast<int64_t>(0)) + lane2[i], dp1);
            dp121 = max(max(dp121, static_cast<int64_t>(0)) + lane1[i], dp12);
            result = max({result, dp1, dp121});
        }
        return result;
    }
};
