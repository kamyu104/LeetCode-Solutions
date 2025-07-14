// Time:  O(n)
// Space: O(1)

// backward simulation
class Solution {
public:
    char processStr(string s, long long k) {
        int64_t l = 0;
        for (const auto& x : s) {
            if (x == '*') {
                l = max(l - 1, static_cast<int64_t>(0));
            } else if (x == '#') {
                l <<= 1;
            } else if (x == '%') {
                continue;
            } else {
                ++l;
            }
        }
        if (k >= l) {
            return '.';
        }
        for (int i = size(s) - 1; i >= 0; --i) {
            const auto& x = s[i];
            if (x == '*') {
                ++l;
            } else if (x == '#') {
                l >>= 1;
                if (k >= l) {
                    k -= l;
                }
            } else if (x == '%') {
                k = (l - 1) - k;
            } else {
                if (--l == k) {
                    return x;
                }
            }
        }
        return 'x';
    }
};
