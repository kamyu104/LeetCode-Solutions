// Time:  O(n^2)
// Space: O(n)

// dp, backtracing
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        const auto& check = [&](int i, int j) {
            if (!(groups[i] != groups[j] && size(words[i]) == size(words[j]))) {
                return false;
            }
            int cnt = 0;
            for (int k = 0; k < size(words[i]); ++k) {
                cnt += words[i][k] != words[j][k] ? 1 : 0;
                if (cnt == 2) {
                    return false;
                }
            }
            return cnt == 1;
        };

        vector<pair<int, int>> dp(n, pair(1, -1));
        int i = -1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (check(j, i)) {
                    dp[i] = max(dp[i], pair(dp[j].first + 1, j));
                }
            }
        }
        vector<string> result;
        for (int i = distance(cbegin(dp), max_element(cbegin(dp), cend(dp)));i != -1; i = dp[i].second) {
            result.emplace_back(words[i]);
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// dp, backtracing
class Solution2 {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        const auto& check = [&](int i, int j) {
            if (!(groups[i] != groups[j] && size(words[i]) == size(words[j]))) {
                return false;
            }
            int cnt = 0;
            for (int k = 0; k < size(words[i]); ++k) {
                cnt += words[i][k] != words[j][k] ? 1 : 0;
                if (cnt == 2) {
                    return false;
                }
            }
            return cnt == 1;
        };

        vector<pair<int, int>> dp(n, pair(1, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (check(j, i)) {
                    dp[i] = max(dp[i], pair(dp[j].first + 1, j));
                }
            }
        }
        vector<string> result;
        for (int i = distance(cbegin(dp), max_element(cbegin(dp), cend(dp)));i != -1; i = dp[i].second) {
            result.emplace_back(words[i]);
        }
        reverse(begin(result), end(result));
        return result;
    }
};
