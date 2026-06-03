// Time:  O(rlogr + n * b), r = max(f for f, _ in items)
// Space: O(r + b)

// freq table, knapsack dp, greedy
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        static const int NEG_INF = numeric_limits<int>::min();

        int max_f = 0;
        for (const auto& x : items) {
            max_f = max(max_f, x[0]);
        }
        vector<int> cnt(max_f + 1);
        for (const auto& x : items) {
            ++cnt[x[0]];
        }
        vector<int> total(size(cnt));
        for (int i = 1; i < size(cnt); ++i) {
            if (!cnt[i]) {
                continue;
            }
            for (int j = i; j < size(cnt); j += i) {
                total[i] += cnt[j];
            }
        }
        vector<int> dp(budget + 1, NEG_INF);
        dp[0] = 0;
        for (const auto& x : items) {
            for (int i = size(dp) - 1; i - x[1] >= 0; --i) {
                if (dp[i - x[1]] == NEG_INF) {
                    continue;
                }
                dp[i] = max(dp[i], dp[i - x[1]] + total[x[0]]);
            }
        }
        int min_p = numeric_limits<int>::max();
        for (const auto& x : items) {
            min_p = min(min_p, x[1]);
        }
        int result = 0;
        for (int i = 0; i < size(dp); ++i) {
            if (dp[i] == NEG_INF) {
                continue;
            }
            result = max(result, dp[i] + (budget - i) / min_p);
        }
        return result;
    }
};

// Time:  O(rlogr + n * b), r = max(f for f, _ in items)
// Space: O(r + b)
// freq table, knapsack dp, greedy
class Solution2 {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        static const int NEG_INF = numeric_limits<int>::min();

        int max_f = 0;
        for (const auto& x : items) {
            max_f = max(max_f, x[0]);
        }
        vector<int> cnt(max_f + 1);
        for (const auto& x : items) {
            ++cnt[x[0]];
        }
        vector<int> total(size(cnt));
        for (int i = 1; i < size(cnt); ++i) {
            if (!cnt[i]) {
                continue;
            }
            for (int j = i; j < size(cnt); j += i) {
                total[i] += cnt[j];
            }
        }
        vector<int> dp(budget + 1, NEG_INF);
        dp[0] = 0;
        for (const auto& x : items) {
            for (int i = size(dp) - 1; i - x[1] >= 0; --i) {
                if (dp[i - x[1]] == NEG_INF) {
                    continue;
                }
                dp[i] = max(dp[i], dp[i - x[1]] + total[x[0]]);
            }
            for (int i = x[1]; i < size(dp); ++i) {
                if (dp[i - x[1]] == NEG_INF) {
                    continue;
                }
                dp[i] = max(dp[i], dp[i - x[1]] + 1);
            }
        }
        return ranges::max(dp);
    }
};
