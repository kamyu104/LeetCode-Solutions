// Time:  O(logn)
// Space: O(1)

// bitmasks, combinatorics
class Solution {
public:
    int countBinaryPalindromes(long long n) {
        const auto& length = [&](int64_t n) {
            int result = 0;
            for (; n; n >>= 1) {
                ++result;
            }
            return result;
        };

        const auto& reverse = [](int64_t n, int l) {
            int64_t result = 0;
            for (int i = 0; i < l; ++i) {
                if (n & (1 << i)) {
                    result |= 1 << ((l - 1) - i);
                }
            }
            return result;
        };

        const auto& l = length(n) / 2;
        const auto& p = ((n >> l) << l) | reverse(n >> (length(n) - l), l);
        return ((1 << l) - 1) + (n >> l) + (p <= n ? 1 : 0);
    }
};

// Time:  O(logn)
// Space: O(logn)
// bitmasks, combinatorics
class Solution2 {
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
        const int l = size(s) / 2;
        string p = s.substr(0, size(s) - l);
        for (int i = 0; i < l; ++i) {
            p.push_back(s[(l - 1) - i]);
        }
        return ((1 << l) - 1) + (n >> l) + (p <= s ? 1 : 0);
    }
};
