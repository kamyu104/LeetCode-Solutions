// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string truncateSentence(string s, int k) {
        for (int i = 0; i < size(s); ++i) {
            if (s[i] == ' ' && --k == 0) {
                return s.substr(0, i);
            }
        }
        return s;
    }
};
