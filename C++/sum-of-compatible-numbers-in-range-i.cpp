// Time:  O(log(n + k))
// Space: O(log(n + k))

// combinatorics
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        const auto& count = [&](int x) {
            if (x <= 0) {
                return 0;
            }
            const auto& l = bit_width(static_cast<uint32_t>(x));
            vector<int> cnt(l + 1);
            cnt[0] = 1;
            vector<int> total(l + 1);
            for (int i = 0; i < l; ++i) {
                cnt[i + 1] = (n & (1 << i)) == 0 ? cnt[i] * 2 : cnt[i];
                total[i + 1] = (n & (1 << i)) == 0 ? total[i] * 2 + (1 << i) * cnt[i] : total[i];
            }
            int result = 0, prefix = 0;
            for (int i = l - 1; i >= 0; --i) {
                if (!(x & (1 << i))) {
                    continue;
                }
                result += prefix * cnt[i] + total[i];
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
// Space: O(k)
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
