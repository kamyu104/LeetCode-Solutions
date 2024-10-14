// Time:  O(n * m)
// Space: O(n + m)

// dp
class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        static const int NEG_INF = numeric_limits<int>::min();

        vector<int> dp(size(pattern) + 1, NEG_INF);
        dp[0] = 0;
        vector<bool> lookup(size(source));
        for (const auto& x : targetIndices) {
            lookup[x] = true;
        }
        for (int i = 0; i < size(source); ++i) {
            for (int j = size(pattern); j >= 0; --j) {
                if (dp[j] != NEG_INF) {
                    dp[j] += lookup[i];
                }
                if (j - 1 >= 0 && pattern[j - 1] == source[i]) {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
            }
        }
        return dp.back();
    }
};
