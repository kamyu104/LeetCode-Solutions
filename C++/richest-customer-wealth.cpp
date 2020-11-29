// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;
        for (const auto& account : accounts) {
            int total = accumulate(cbegin(account), cend(account), 0);
            result = max(result, total);
        }
        return result;
    }
};
