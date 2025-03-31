// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int prev = 0, curr = 0, mx = 0, cnt1 = 0;
        for (const auto& x : s) {
            if (x == '0') {
                ++curr;
            } else {
                if (curr) {
                    prev = curr;
                    curr = 0;
                }
                ++cnt1;
            }
            mx = max(mx, prev + curr);
        }
        return mx == prev || mx == curr ? cnt1 : mx + cnt1;
    }
};
