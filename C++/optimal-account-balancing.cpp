// Time:  O(n * 2^n), n is the size of debts.
// Space: O(2^n)

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> account;
        for (const auto& transaction : transactions) {
            account[transaction[0]] += transaction[2];
            account[transaction[1]] -= transaction[2];
        }
        vector<int> debts;
        for (const auto& [_, debt] : account) {
            if (debt) {
                debts.emplace_back(debt);
            }
        }

        vector<int> dp(1 << debts.size());
        vector<int> sums(1 << debts.size());
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0, bit = 1; j < debts.size(); ++j, bit <<= 1) {
                if ((i & bit) == 0) {
                    auto nxt = i | bit;
                    sums[nxt] = sums[i] + debts[j];
                    if (sums[nxt] == 0) {
                        dp[nxt] = max(dp[nxt], dp[i] + 1);
                    } else {
                        dp[nxt] = max(dp[nxt], dp[i]);
                    }
                }
            }
        }
        return debts.size() - dp.back();
    }
};
