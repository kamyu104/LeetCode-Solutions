// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        vector<long long> result;
        vector<long long> dp = {0, expressCost};
        for (int i = 0; i < size(regular); ++i) {
            dp = {min(dp[0] + regular[i], dp[1] + express[i]),
                  min(dp[0] + regular[i] + expressCost, dp[1] + express[i])};
            result.emplace_back(min(dp[0], dp[1]));
        }
        return result;
    }
};
