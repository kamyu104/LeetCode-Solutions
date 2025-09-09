// Time:  O(logn)
// Space: O(logn)

// math, combinatorics
class Solution {
public:
    int countBinaryPalindromes(long long n) {
        const auto& to_binary = [&](int64_t n) {
            string result;
            for (; n; n >>= 1) {
                result.push_back(n & 1);
            }
            reverse(begin(result), end(result));
            return result;
        };

        const auto& s = to_binary(n);
        const int l = size(s);
        string p = s.substr(0, (l + 1) / 2);
        for (int i = 0; i < l / 2; ++i) {
            p.push_back(s[(l / 2 - 1) - i]);
        }
        return ((1 << (l / 2)) - 1) + (n >> (l / 2)) + (p <= s ? 1 : 0);
    }
};
