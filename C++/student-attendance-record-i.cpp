// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkRecord(string s) {
        int count_A = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'A') {
                if (++count_A == 2) {
                    return false;
                }
            }
            if (i + 2 < s.length() && s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L') {
                return false;
            }
        }
        return true;
    }
};
