// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    char kthCharacter(string s, long long k) {
        int i = 0;
        for (int l = 0; i < size(s); ++i) {
            if (s[i] == ' ') {
                l = 0;
                --k;
            } else {
                k -= ++l;
            }
            if (k < 0) {
                break;
            }
        }
        return s[i];
    }
};
