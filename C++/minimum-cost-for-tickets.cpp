// Time:  O(n)
// space: O(n)

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        static vector<int> durations{1, 7, 30};

        vector<int> dp(days.size() + 1, numeric_limits<int>::max());
        dp[0] = 0;
        vector<int> last_buy_days{0, 0, 0};
        for (int i = 1; i < days.size() + 1; ++i) {
            for (int j = 0; j < durations.size(); ++j) {
                while (i - 1 < days.size() &&
                       days[i-1] > days[last_buy_days[j]]+durations[j] - 1) {
                    ++last_buy_days[j];  // Time: O(n)
                }
                dp[i] = min(dp[i], dp[last_buy_days[j]]+costs[j]);
            }
        }
        return dp.back();
    }
};

// Time:  O(W) W is the maximum numbered day in your travel plan.
// space: O(1)
class Solution2 {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        static vector<int> durations{1, 7, 30};
        deque<int> dp(30, 0);
        auto iter = days.begin();
        for (int i = 1; iter != days.end(); ++i) {
            if(i == *iter){
                dp.emplace_back() = min({dp[dp.size()-durations[0]]+costs[0],
                                         dp[dp.size()-durations[1]]+costs[1],
                                         dp[dp.size()-durations[2]]+costs[2]});
                iter++;
            } else {
                dp.emplace_back() = dp.back();
            }
            dp.pop_front();
        }
        return dp.back();
    }
};