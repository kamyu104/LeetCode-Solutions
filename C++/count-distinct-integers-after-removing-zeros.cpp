// Time:  O(logn)
// Space: O(1)

// combinatorics
class Solution {
public:
    long long countDistinct(long long n) {
        const auto& reverse = [](int64_t n) {
            int64_t result = 0, base = 1;
            for (; n; n /= 10, base *= 9) {
                result = result * 10 + n % 10;
            }
            return pair(result, base);
        };

        auto [m, base] = reverse(n + 1);
        int64_t result = (base - 9) / (9 - 1);
        base /= 9;
        for (; base; base /= 9, m /= 10) {
            const int r = m % 10;
            if (r == 0) {
                break;
            }
            result += (r - 1) * base;
        }
        return result;
    }
};

// Time:  O(logn)
// Space: O(logn)
// combinatorics
class Solution2 {
public:
    long long countDistinct(long long n) {
        const auto& s = to_string(n);
        int64_t base = pow(9, size(s));
        int64_t result = (base - 9) / (9 - 1);
        base /= 9;
        for (const auto& x : s) {
            if (x == '0') {
                break;
            }
            result += ((x - '0') - 1) * base;
            base /= 9;
        }
        if (base == 0) {
            ++result;
        }
        return result;
    }
};
