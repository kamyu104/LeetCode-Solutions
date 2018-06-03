// Time:  O(m + n)
// Space: O(1)

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int skipS = 0, skipT = 0;
        for (int i = S.length() - 1, j = T.length() - 1;
             i >= 0 || j >= 0;
             --i, --j) {
            auto x = findNextChar(S, &i, &skipS);
            auto y = findNextChar(T, &j, &skipT);
            if (x != y) {
                return false;
            }
        }
        return true;
    }

private:
    char findNextChar(const string& s, int *i, int *skip) {
        for (; *i >= 0; --(*i)) {
            if (s[*i] == '#') {
                ++(*skip);
            } else if ((*skip) > 0) {
                --(*skip);
            } else {
                return s[*i];
            }
        }
        return '\0';
    }
};
