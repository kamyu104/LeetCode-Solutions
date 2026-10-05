// Time:  O(logr)
// Space: O(1)

// math
class Solution {
public:
    long long countEvenlyGoodIntegers(long long l, long long r) {
        const auto& count = [](auto n) {
            if (n <= 0) {
                return 0ll;
            }
            int parity = 0;
            for (auto q = n / 10; q; q /= 10) {
                parity ^= (q % 10) % 2 == 0;
            }
            const auto& q = n / 10, &r = n % 10;
            return parity ? q * 5 + r / 2 + 1 : q * 5 + (r + 1) / 2;
        };

        return count(r) - count(l - 1);
    }
};
