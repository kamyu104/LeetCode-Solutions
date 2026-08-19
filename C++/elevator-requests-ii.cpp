// Time:  O(m^2), m = len(requests)
// Space: O(m)

// dp
class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        static const auto INF = numeric_limits<int64_t>::max();

        if (find(cbegin(requests), cend(requests), start) == cend(requests)) {
            requests.emplace_back(start);
        }
        ranges::sort(requests);
        const int k = distance(cbegin(requests), find(cbegin(requests), cend(requests), start));
        vector<vector<int64_t>> dp(2, vector<int64_t>(size(requests), INF));
        dp[0][k] = dp[1][k] = 0;
        for (int l = 1; l < size(requests); ++l) {
            vector<vector<int64_t>> new_dp(2, vector<int64_t>(size(requests), INF));
            for (int i = max(k - l + 1, 0); i <= min(static_cast<int>(size(requests)) - l, k); ++i) {
                const auto& j = i + l - 1;
                if (i - 1 >= 0) {
                    if (dp[0][i] != INF) {
                        new_dp[0][i - 1] = min(new_dp[0][i - 1], dp[0][i] + (requests[i] - requests[i - 1]) * static_cast<int64_t>(size(requests) - l));
                    }
                    if (dp[1][i] != INF) {
                        new_dp[0][i - 1] = min(new_dp[0][i - 1], dp[1][i] + (requests[j] - requests[i - 1]) * static_cast<int64_t>(size(requests) - l));
                    }
                }
                if (j + 1 < size(requests)) {
                    if (dp[0][i] != INF) {
                        new_dp[1][i] = min(new_dp[1][i], dp[0][i] + (requests[j + 1] - requests[i]) * static_cast<int64_t>(size(requests) - l));
                    }
                    if (dp[1][i] != INF) {
                        new_dp[1][i] = min(new_dp[1][i], dp[1][i] + (requests[j + 1] - requests[j]) * static_cast<int64_t>(size(requests) - l));
                    }
                }
            }
            dp = move(new_dp);
        }
        return min(dp[0][0], dp[1][0]);
    }
};
