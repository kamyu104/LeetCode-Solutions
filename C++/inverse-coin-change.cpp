// Time:  O(n^2)
// Space: O(1)

// dp
class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> result;
        for (int i = 1; i <= size(numWays); ++i) {
            if (numWays[i - 1] == 1) {
                result.emplace_back(i);
                for (int j = size(numWays); j >= i; --j) {
                    numWays[j - 1] -= (j - i) - 1 >= 0 ? numWays[(j - i) - 1] : 1;
                }
            }
            if (numWays[i - 1]) {
                return {};
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// dp
class Solution2 {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> result;
        vector<int> dp(size(numWays) + 1);
        dp[0] = 1;
        for (int i = 1; i <= size(numWays); ++i) {
            if (numWays[i - 1] - dp[i] == 1) {
                result.emplace_back(i);
                for (int j = i; j <= size(numWays); ++j) {
                    dp[j] += dp[j - i];
                }
            }
            if (numWays[i - 1] - dp[i]) {
                return {};
            }
        }
        return result;
    }
};
