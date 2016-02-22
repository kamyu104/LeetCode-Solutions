// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void reverseWords(string &s) {
        // Reverse the whole string first.
        reverse(s.begin(), s.end());

        size_t start = 0, end = 0, len = 0;
        while ((start = s.find_first_not_of(" ", end)) != string::npos) {
            if ((end = s.find(" ", start)) == string::npos) {
                end = s.length();
            }
            // Reverse each word in the string.
            reverse(s.begin() + start, s.begin() + end);

            // Shift the word to avoid extra space.
            move(s.begin() + start, s.begin() + end, s.begin() + len);
            len += end - start;
            s[len++] = ' ';
        }
        s.resize(len ? len - 1 : 0);
    }
};
