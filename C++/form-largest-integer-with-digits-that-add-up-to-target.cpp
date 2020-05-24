// Time:  O(t)
// Space: O(t)

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(1);
        dp[0] = 0;
        for (int t = 1; t <= target; ++t) {
            dp.emplace_back(-1);
            for (int i = 0; i < 9; ++i) {
                if (t < cost[i] || dp[t - cost[i]] < 0) {
                    continue;
                }
                dp[t] = max(dp[t], dp[t - cost[i]] + 1);
            }
        }
        if (dp[target] < 0) {
            return "0";
        }
        string result;
        for (int i = 8; i >= 0; --i) {
            while (target >= cost[i] && dp[target] == dp[target - cost[i]] + 1) {
                target -= cost[i];
                result.push_back('1' + i);
            }
        }
        return result;
    }
};

// Time:  O(t)
// Space: O(t)
class Solution2 {
public:
    string largestNumber(vector<int>& cost, int target) {
        const auto& key = [](const auto& a) {
            return pair{accumulate(cbegin(a), cend(a), 0), a};
        };
        vector<vector<int>> dp = {vector<int>(9)};
        for (int t = 1; t <= target; ++t) {
            dp.emplace_back();
            for (int i = 0; i < 9; ++i) {
                if (t < cost[i] || dp[t - cost[i]].empty()) {
                    continue;
                }
                auto curr = dp[t - cost[i]];
                ++curr[8 - i];
                if (key(curr) > key(dp[t])) {
                    dp[t] = move(curr);
                }
            }
        }
        if (dp.back().empty()) {
            return "0";
        }
        string result;
        for (int i = 0; i < dp.back().size(); ++i) {
            result += string(dp.back()[i], '1' + 8 - i);
        }
        return result;
    }
};
