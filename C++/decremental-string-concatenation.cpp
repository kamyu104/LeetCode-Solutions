// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<int>> dp(2, vector<int>(26, numeric_limits<int>::min()));
        dp[0][words[0].back() - 'a'] = dp[1][words[0][0] - 'a'] = 0;
        for (int i = 1; i < size(words); ++i) {
            vector<vector<int>> new_dp(2, vector<int>(26, numeric_limits<int>::min()));
            for (int right = 0; right < 2; ++right) {
                for (int c = 0; c < 26; ++c) {
                    if (dp[right][c] == numeric_limits<int>::min()) {
                        continue;
                    }
                    const int l = right ? c : words[i - 1][0] - 'a';
                    const int r = !right ? c : words[i - 1].back() - 'a';
                    new_dp[0][r] = max(new_dp[0][r], dp[right][c] + static_cast<int>(words[i].back() - 'a' == l));
                    new_dp[1][l] = max(new_dp[1][l], dp[right][c] + static_cast<int>(r == words[i][0] - 'a'));
                }
            };
            dp = move(new_dp);
        }
        int total = accumulate(cbegin(words), cend(words), 0, [](const auto& accu, const auto& w) {
            return accu + size(w);
        });
        int mx = 0;
        for (int right = 0; right < 2; ++right) {
            for (int c = 0; c < 26; ++c) { 
                mx = max(mx, dp[right][c]);
            }
        }
        return total - mx;
    }
};
