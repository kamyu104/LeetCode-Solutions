// Time:  O(n)
// Space: O(1)

// greedy, case works
class Solution {
public:
    int minFlips(string s) {
        const int cnt0 = ranges::count(s, '0');
        const int cnt1 = size(s) - cnt0;
        return min({
            cnt0,
            max(cnt1 - 1, 0),
            max(cnt1 - (s[0] == '1' ? 1 : 0) - (s.back() == '1' ? 1 : 0), 0)
        });
    }
};
