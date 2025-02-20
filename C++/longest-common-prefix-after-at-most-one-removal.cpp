// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    int longestCommonPrefix(string s, string t) {
        int result = 0;
        bool removed = false;
        for (int i = 0, j = 0; i < size(s) && j <size(t);) {
            if (s[i] == t[j]) {
                ++result;
                ++i, ++j;
            } else if (!removed) {
                removed = true;
                ++i;
            } else {
                break;
            }
        }
        return result;
    }
};
