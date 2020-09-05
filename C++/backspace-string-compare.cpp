// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        for (int i = S.length() - 1, j = T.length() - 1; i >= 0 || j >= 0; --i, --j) {
            if (findNextChar(S, &i) != findNextChar(T, &j)) {
                return false;
            }
        }
        return true;
    }

private:
    char findNextChar(const string& s, int *i) {
        int skip = 0;
        for (; *i >= 0; --(*i)) {
            if (s[*i] == '#') {
                ++skip;
            } else if (skip > 0) {
                --skip;
            } else {
                return s[*i];
            }
        }
        return '\0';
    }
};
