// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '?') {
                continue;
            }
            for (s[i] = 'a'; s[i] <= 'c'; ++s[i]) {
                if ((i == 0 || s[i - 1] != s[i]) && (i == s.size() - 1 || s[i + 1] != s[i])) {
                    break;
                }
            }
        }
        return s;
    }
};
