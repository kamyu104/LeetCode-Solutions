// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void reverseWords(string &s) {
        // Reverse the whole string first.
        reverse(s.begin(), s.end());

        size_t start = 0, end;
        while ((end = s.find(" ", start)) != string::npos) {
            // Reverse each word in the string.
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        // Reverse the last word.
        reverse(s.begin() + start, s.end());

        // Remove beginning and trailing spaces.
        int new_len = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ' ') {
                s[new_len++] = s[i];
                if (s[i + 1] == ' ' || i == s.length() - 1) {
                    s[new_len++] = ' ';
                }
            }
        }
        s.resize(new_len == 0 ? 0 : new_len - 1);
    }
};
