// Time:  O(n * 2^n), n is the size of debts.
// Space: O(2^n)

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> account;
        for (const auto& transaction 
             : transactions) {
            account[transaction[0]] += transaction[2];
            account[transaction[1]] -= transaction[2];
        }
        vector<int> debts;
        for (const auto& kvp: account) {
            if (kvp.second) {
                debts.emplace_back(kvp.second);
            }
        }

        vector<int> dp(1 << debts.size());
        vector<int> sums(1 << debts.size());
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < debts.size(); ++j) {
                if ((i & (1 << j)) == 0) {
                    auto nxt = i | (1 << j);
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
