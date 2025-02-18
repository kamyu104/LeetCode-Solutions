// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        for (int i = 0, l = 0; i < size(s); ++i) {
            ++l;
            if (i + 1 == size(s) || s[i] != s[i + 1]) {
                if (l == k) {
                    return true;
                }
                l = 0;
            }
        }
        return false;
    }
};
