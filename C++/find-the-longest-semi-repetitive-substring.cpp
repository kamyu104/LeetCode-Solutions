// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int result = 0, left = 0, prev = 0;
        for (int right = 0; right < size(s); ++right) {
            if (right - 1 >= 0 && s[right - 1] == s[right]) {
                left = prev;
                prev = right;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
