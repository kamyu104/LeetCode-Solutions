// Time:  O(n)
// Space: O(1)

// inplace solution
class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 0, j = 0;
        for (int i = 0; i < size(s); ++i) {
            cnt = (i >= 1 && s[i] == s[i - 1]) ? cnt + 1 : 1;
            if (cnt < 3) {
                s[j++] = s[i];
            }
        }
        s.resize(j);
        return s;
    }
};
