// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        static const int INF = numeric_limits<int>::max();

        int a = INF, b = INF, c = 0;
        for (int i = 0; i < n; ++i) {
            tie(a, b, c) = tuple(b, c, costs[i] + min({i - 2 >= 0 ? a + 3 * 3 : INF,
                                                       i - 1 >= 0 ? b + 2 * 2 : INF,
                                                       c + 1 * 1}));
        }
        return c;
    }
};

// Time:  O(n)
// Space: O(n)
// dp
class Solution2 {
public:
    int climbStairs(int n, vector<int>& costs) {
        static const int INF = numeric_limits<int>::max();

        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = costs[i] + min({i - 2 >= 0 ? dp[i - 2] + 3 * 3 : INF,
                                        i - 1 >= 0 ? dp[i - 1] + 2 * 2 : INF,
                                        dp[i] + 1 * 1});
        }
        return dp[n];
    }
};
