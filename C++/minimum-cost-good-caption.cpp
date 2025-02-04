// Time:  O(26 * n)
// Space: O(26 * n)

// dp, backtracing
class Solution {
public:
    string minCostGoodCaption(string caption) {
        static const int L = 3;

        const int n = size(caption);
        if (n < L) {
            return "";
        }
        vector<vector<pair<int, int>>> dp(n - L + 1, vector<pair<int, int>>(26));
        vector<pair<int, int>> mn(n - L + 1);
        for (int i = n - L; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                if (i == n - L) {
                    for (int k = i; k < i + L; ++k) {
                        dp[i][j].first += abs((caption[k] - 'a') - j);
                    }
                    dp[i][j].second = L;
                    continue;
                }
                dp[i][j] = pair(dp[i + 1][j].first + abs((caption[i] - 'a') - j), 1);
                if (i + L < n - 2) {
                    auto [curr, c] = mn[i + L];
                    for (int k = i; k < i + L; ++k) {
                        curr += abs((caption[k] - 'a') - j);
                    }
                    if (curr < dp[i][j].first || (curr == dp[i][j].first && c < j)) {
                        dp[i][j] = pair(curr, L);
                    }
                }
            }
            mn[i] = pair(dp[i][0].first, 0);
            for (int j = 1; j < 26; ++j) {
                mn[i] = min(mn[i], pair(dp[i][j].first, j));
            }
        }
        string result;
        for (int i = 0, j = mn[0].second, l = 1; i != n; i += l) {
            if (l == L) {
                j = mn[i].second;
            }
            l = dp[i][j].second;
            result.append(l, 'a' + j);
        }
        return result;
    }
};
