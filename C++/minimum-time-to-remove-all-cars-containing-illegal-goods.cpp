// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int minimumTime(string s) {
        int result = size(s), dp = 0;
        for (int i = 0; i < size(s); ++i) {
            dp = min(dp + 2 * (s[i] == '1'), i + 1);
            result = min(result, dp + ((static_cast<int>(size(s)) - 1) - i));
        }
        return result;
    }
};
