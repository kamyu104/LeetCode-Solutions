// Time:  O(n + 26)
// Space: O(26)

// freq table
class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        int mn = numeric_limits<int>::max(), mx = 0;
        for (const auto& x : cnt) {
            if (!x) {
                continue;
            }
            if (x % 2 == 0) {
                mn = min(mn, x);
            } else {
                mx = max(mx, x);
            }
        }
        return mx - mn;
    }
};
