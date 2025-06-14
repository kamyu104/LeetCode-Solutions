// Time:  O(n^2)
// Space: O(26^2)

// dp, greedy
class Solution {
public:
    int minOperations(string word1, string word2) {
        const int n = size(word1);
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < 2 * n - 1; ++i) {
            unordered_map<char, unordered_map<char, int>> cnt;
            for (int left = i / 2, right = (i + 1) / 2, curr = 1; 0 <= left && right < n; --left, ++right) {
                for (int j = 0; j < 2; ++j) {
                    const auto& x = word1[left], &y = word2[right];
                    if (x != y && (left != right || j == 0)) {
                        if (cnt[y][x]) {
                            --cnt[y][x];
                        } else {
                            ++cnt[x][y];
                            ++curr;
                        }
                    }
                    swap(left, right);
                }
                dp[left][right] = curr;
            }
        }
        vector<int> dp2(n + 1, numeric_limits<int>::max());
        dp2[0] = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<char, unordered_map<char, int>> cnt;
            for (int j = i, curr = 0; j >= 0; --j) {
                const auto& x = word1[j], &y = word2[j];
                if (x != y) {
                    if (cnt[y][x]) {
                        --cnt[y][x];
                    } else {
                        ++cnt[x][y];
                        ++curr;
                    }
                }
                dp2[i + 1] = min(dp2[i + 1], dp2[j] + min(curr, dp[j][i]));
            }
        }
        return dp2[n];
    }
};
