// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        static const int MOD = 1e9 + 7;

        vector<int> dp(size(nextVisit));
        for (int i = 1; i < size(nextVisit); ++i) {
            dp[i] = (dp[i - 1] + 1ull + (dp[i - 1] - dp[nextVisit[i - 1]]) + 1 + MOD) % MOD;
        }
        return dp.back();
    }
};
