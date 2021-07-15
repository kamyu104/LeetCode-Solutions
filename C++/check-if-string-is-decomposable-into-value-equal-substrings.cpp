// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isDecomposable(string s) {
        bool found = false;
        for (int i = 0, l; i < size(s); i += l) {
            l = 1;
            for (int j = i + 1; j < min(i + 3, int(size(s))); ++j, ++l) {
                if (s[j] != s[i]) {
                    break;
                }
            }
            if (l < 2) {
                return false;
            }
            if (l == 2) {
                if (found) {
                    return false;
                }
                found = true;
            }
        }
        return found;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    bool isDecomposable(string s) {
        bool found = false;
        for (int i = 0, l = 0; i < size(s); ++i) {
            if (!l || s[i] != s[i - 1]) {
                if (l) {
                    return false;
                }
                l = 1;
                continue;
            }
            ++l;
            if (l == 2) {
                if (i == size(s) - 1 || s[i] != s[i + 1]) {
                    if (found) {
                        return false;
                    }
                    found = true;
                    l = 0;
                }
            } else if (l == 3) {
                l = 0;
            }
        }
        return found;
    }
};
