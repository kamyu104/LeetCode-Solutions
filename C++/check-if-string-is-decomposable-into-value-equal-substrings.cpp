// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isDecomposable(string s) {
        bool found = false;
        int l = 0;
        for (int i = 0; i < size(s); ++i) {
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
