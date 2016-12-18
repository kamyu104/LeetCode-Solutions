// Time:  O(2^n), n is the size of debt.
// Space: O(2^n)

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> account;
        for (const auto& transaction : transactions) {
            account[transaction[0]] += transaction[2];
            account[transaction[1]] -= transaction[2];
        }

        vector<int> debt;
        for (const auto& kvp : account) {
            if (kvp.second) {
                debt.emplace_back(kvp.second);
            }
        }
        if (debt.empty()) {
            return 0;
        }

        const auto n = 1 << debt.size();
        vector<int> dp(n, numeric_limits<int>::max()), subset;
        for (int i = 1; i < n; ++i) {
            int net_debt = 0, number = 0;
            for (int j = 0; j < debt.size(); ++j) {
                if (i & 1 << j) {
                    net_debt += debt[j];
                    ++number;
                }
            }
            if (net_debt == 0) {
                dp[i] = number - 1;
                for (const auto& s: subset) {
                    if ((i & s) == s) {
                        if (dp[s] != numeric_limits<int>::max() &&
                            dp[i - s] != numeric_limits<int>::max()) {
                            dp[i] = min(dp[i], dp[s] + dp[i - s]);
                        }
                    }
                }
                subset.emplace_back(i);
            }
        }
        return dp.back();
    }
};
