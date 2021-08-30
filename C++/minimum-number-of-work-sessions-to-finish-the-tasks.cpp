// Time:  O(n * 2^n)
// Space: O(2^n)

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        // dp[mask]: min used time by choosing tasks in mask bitset
        vector<int> dp(1 << size(tasks), numeric_limits<int>::max());
        dp[0] = 0;
        for (int mask = 0; mask < size(dp) - 1; ++mask) {
            int basis = 1;
            for (auto task : tasks) {
                const int new_mask = mask | basis;
                basis <<= 1;
                if (new_mask == mask) {
                    continue;
                }
                if (dp[mask] % sessionTime + task > sessionTime) {
                    task += sessionTime - dp[mask] % sessionTime;  // take a break
                }
                dp[new_mask] = min(dp[new_mask], dp[mask] + task);
            }
        }
        return (dp.back() + sessionTime - 1) / sessionTime;
    }
};

// Time:  O(n * 2^n)
// Space: O(2^n)
class Solution2 {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        // dp[mask][0]: min number of sessions by choosing tasks in mask bitset
        // dp[mask][1]: min used time of last session by choosing tasks in mask bitset
        vector<pair<int, int>> dp(1 << size(tasks), pair(numeric_limits<int>::max(), numeric_limits<int>::max()));
        dp[0] = {0, sessionTime};
        for (int mask = 0; mask < size(dp) - 1; ++mask) {
            int basis = 1;
            for (const auto& task : tasks) {
                const int new_mask = mask | basis;
                basis <<= 1;
                if (new_mask == mask) {
                    continue;
                }
                if (dp[mask].second + task <= sessionTime) {
                    dp[new_mask] = min(dp[new_mask], {dp[mask].first, dp[mask].second + task});
                } else {
                    dp[new_mask] = min(dp[new_mask], {dp[mask].first + 1, task});
                }
            }
        }
        return dp.back().first;
    }
};
