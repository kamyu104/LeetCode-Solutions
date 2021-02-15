// Time:  O(n)
// Space; O(1)

class Solution {
public:
    int countHomogenous(string s) {
        static const int MOD = 1e9 + 7;
        int cnt = 0, result = 0;
        for (int i = 0; i < size(s); ++i) {
            if (i > 0 && s[i - 1] == s[i]) {
                ++cnt;
            } else {
                cnt = 1;
            }
            result = (result + cnt) % MOD;
        }
        return result;
    }
};
