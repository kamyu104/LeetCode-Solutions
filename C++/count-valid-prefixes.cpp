// Time:  O(n)
// Space: O(1)

// prefix sum
class Solution {
public:
    int countValidPrefixes(string s) {
        int result = 0;
        for (int i = 0, prefix = 0; i < size(s); ++i) {
            prefix += s[i] == '1' ? 1 : -1;
            if (abs(prefix) <= 1) {
                ++result;
            }
        }
        return result;
    }
};
