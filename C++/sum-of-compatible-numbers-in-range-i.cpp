// Time:  O(log(n + k))
// Space: O(1)

// bitmasks, combinatorics
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        const auto& count = [&](int x) {
            if (x <= 0) {
                return 0;
            }
            const auto& l = bit_width(static_cast<uint32_t>(x));
            int total = 0, cnt = 1;
            for (int i = 0; i < l; ++i) {
                if (n & (1 << i)) {
                    continue;
                }
                total = total * 2 + (1 << i) * cnt;
                cnt *= 2;
            }
            int result = 0, prefix = 0;
            for (int i = l - 1; i >= 0; --i) {
                if ((n & (1 << i)) == 0) {
                    if (!(n & (1 << i))) {
                        cnt /= 2;
                        total = (total - (1 << i) * cnt) / 2;
                    }
                }
                if (!(x & (1 << i))) {
                    continue;
                }
                result += prefix * cnt + total;
                if (n & (1 << i)) {
                    return result;
                }
                prefix |= 1 << i;
            }
            result += prefix;
            return result;
        };

        return count(n + k) - count((n - k) - 1);
    }
};

// Time:  O(k)
// Space: O(1)
// simulation
class Solution2 {
public:
    int sumOfGoodIntegers(int n, int k) {
        int result = 0;
        for (int i = max(n - k, 1); i <= n + k; ++i) {
            if ((n & i) == 0) {
                result += i;
            }
        }
        return result;
    }
};
