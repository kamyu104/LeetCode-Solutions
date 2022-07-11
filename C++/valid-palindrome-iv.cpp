// Time:  O(n)
// Space: O(1)

// string, two pointers
class Solution {
public:
    bool makePalindrome(string s) {
        for (int left = 0, right = size(s) - 1, cnt = 0; left < right; ++left, --right) {
            if (s[left] != s[right] && ++cnt > 2) {
                return false;
            }
        }
        return true;
    }
};
