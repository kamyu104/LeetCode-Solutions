// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        int prev = 0; // f[n - 2]
        int cur = 1;  // f[n - 1]

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                cur = 0; // f[n - 1] = 0
            }
            if (i == 0 ||
                !(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
                prev = 0; // f[n - 2] = 0
            }

            int tmp = cur;
            cur += prev; // f[n] = f[n - 1] + f[n - 2]
            prev = tmp;
        }

        return cur;
    }
};
