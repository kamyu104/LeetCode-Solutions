// Time:  O(logk)
// Space: O(logk)

// combinatorics
class Solution {
public:
    int waysToReachStair(int k) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const auto& ceil_log2_x = [&](int x) {
            return bit_length(x - 1);
        };
    
        int l = ceil_log2_x(k);
        for (; (1ll << l) - k <= l + 1; ++l);
        vector<__int128> fact(l + 1, 1);
        for (int i = 0; i + 1 < size(fact); ++i) {
            fact[i + 1] = fact[i] * (i + 1);
        }
        const auto& nCr = [&](int n, int r) {
            if (!(0 <= r && r <= n)) {
                return static_cast<__int128>(0);
            }
            return fact[n] / fact[r] / fact[n - r];
        };

        int result = 0;
        for (int i = 0; i < l; ++i) {
            result += nCr(i + 1, (1 << i) - k);
        }
        return result;
    }
};
