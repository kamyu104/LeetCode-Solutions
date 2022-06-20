// Time:  O(n)
// Space: O(1)

// greedy
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int result = 0;
        for (int i = size(s) - 1, base = 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++result;
            } else if (base <= k) {
                k -= base;
                ++result;
            }
            if (base <= k) {
                base <<= 1;
            }
        }
        return result;
    }
};
