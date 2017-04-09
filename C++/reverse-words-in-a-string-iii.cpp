// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0, j = 0; j <= s.length(); ++j) {
            if (j == s.length() || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        return s;
    }
};
