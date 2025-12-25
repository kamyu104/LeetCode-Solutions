// Time:  O(n + 26)
// Space: O(26)

// freq table
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int64_t total = accumulate(cbegin(cost), cend(cost), 0L);
        vector<int64_t> cnt(26);
        for (int i = 0; i < size(s); ++i) {
            cnt[s[i] - 'a'] += cost[i];
        }
        return total - ranges::max(cnt);
    }
};
