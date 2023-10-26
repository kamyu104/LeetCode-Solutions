// Time:  O(n * nlogn * n + n^2 * k) = O(n^3 * logn + n^2 * k)
// Space: O(n * nlogn + n * k) = O(n^2 * logn + n * k)

// number theory, dp
class Solution {
public:
    int minimumChanges(string s, int k) {
        vector<vector<int>> divisors(size(s) + 1);
        for (int i = 1; i < size(divisors); ++i) {
            for (int j = i; j < size(divisors); j += i) {
                divisors[j].emplace_back(i);
            }
        }    
        vector<vector<unordered_map<int, int>>> dp(size(s), vector<unordered_map<int, int>>(size(s)));
        for (int l = 1; l <= size(s); ++l) {
            for (int left = 0; left + l - 1 < size(s); ++left) {
                const int right = left + l - 1;
                for (const auto& d : divisors[l]) {
                    int c = 0;
                    for (int i = 0; i < d; ++i) {
                        if (s[left + i] != s[right - (d - 1) + i]) {
                            ++c;
                        }
                    }
                    dp[left][right][d] = (left + d < right - d ? dp[left + d][right - d][d] : 0) + c;
                }
            }
        }
        vector<vector<int>> dp2(size(s) + 1, vector<int>(k + 1, size(s)));
        dp2[0][0] = 0;
        for (int i = 0; i < size(s); ++i) {
            for (int j = 0; j < i; ++j) {
                int c = size(s);
                for (const auto& d : divisors[i - j + 1]) {
                    if (d != i - j + 1) {
                        c = min(c, dp[j][i][d]);
                    }
                }
                for (int l = 0; l < k; ++l) {
                    dp2[i + 1][l + 1] = min(dp2[i + 1][l + 1], dp2[j][l] + c);
                }
            }
        }
        return dp2[size(s)][k];
    }
};
