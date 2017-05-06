// Time:  O(n^2 * k)
// Space: O(k)

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if (days.empty() || flights.empty()) {
            return 0;
        }
        vector<vector<int>> dp(2, vector<int>(days.size()));
        for (int week = days[0].size() - 1; week >= 0; --week) {
            for (int cur_city = 0; cur_city < days.size(); ++cur_city) {
                dp[week % 2][cur_city] = days[cur_city][week] + dp[(week + 1) % 2][cur_city];
                for (int dest_city = 0; dest_city < days.size(); ++dest_city) {
                    if (flights[cur_city][dest_city] == 1) {
                        dp[week % 2][cur_city] = max(dp[week % 2][cur_city],
                                                     days[dest_city][week] + dp[(week + 1) % 2][dest_city]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
