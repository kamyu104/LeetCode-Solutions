// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    int firstMatchingIndex(string s) {
        for (int i = 0; 2 * i < size(s); ++i) {
            if (s[i] == s[size(s) - 1 - i]) {
                return i;
            }
        }
        return -1;
    }
};
