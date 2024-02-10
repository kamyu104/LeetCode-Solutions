// Time:  O(logb)
// Space: O(1)

// hash table, bitmask, combinatorics
class Solution {
public:
    int numberCount(int a, int b) {
        const auto& count2 = [&](int n) {
            if (n == 0) {
                return 0;
            }
            int result = 1;
            for (int i = 0, cnt = 1; i < n - 1; ++i) {
                cnt *= 9 - i;
                result += cnt;
            }
            return 9 * result;
        };

        const auto& count = [&](int x) {
            int n = 1, base = 1;
            for (; x / (base * 10); base *= 10, ++n);
            int result = count2(n - 1);
            int lookup = 0;
            int cnt = 1;
            for (int i = 0; i < n - 1; ++i) {
                cnt *= 9 - i;
            }
            for (int i = 0; i < n; ++i, base /= 10) {
                const int d = (x / base) % 10;
                const int mask = lookup & (((1 << d) - 1) - (i == 0 ? 1 : 0));
                result += ((d - (i == 0 ? 1 : 0)) - __builtin_popcount(mask)) * cnt;
                cnt /= 9 - i;
                if (lookup & (1 << d)) {
                    break;
                }
                lookup |= 1 << d;
            }
            return result;
        };

        return count(b + 1) - count(a);
    }
};

// Time:  O(logb)
// Space: O(logb)
// hash table, bitmask, combinatorics
class Solution2 {
public:
    int numberCount(int a, int b) {
        vector<int> fact(2, 1);
        const auto& nPr = [&](int n, int k) {
            while (size(fact) <= n) {  // lazy initialization
                fact.emplace_back(fact.back() * size(fact));
            }
            return fact[n] / fact[n - k];
        };

        const auto& count = [&](int x) {
            vector<int> digits;
            for (; x; x /= 10) {
                digits.emplace_back(x % 10);
            }
            reverse(begin(digits), end(digits));
            int result = 0;
            for (int i = 0; i < size(digits) - 1; ++i) {
                result += nPr(9, i);
            }
            result *= 9;
            int lookup = 0;
            for (int i = 0; i < size(digits); ++i) {
                const int mask = lookup & (((1 << digits[i]) - 1) - (i == 0 ? 1 : 0));
                result += ((digits[i] - (i == 0 ? 1 : 0)) - __builtin_popcount(mask)) * nPr(10 - (i + 1), size(digits) - (i + 1));
                if (lookup & (1 << digits[i])) {
                    break;
                }
                lookup |= 1 << digits[i];
            }
            return result;
        };

        return count(b + 1) - count(a);
    }
};

// Time:  O(blogb)
// Space: O(1)
// brute force, hash table, bitmask
class Solution3 {
public:
    int numberCount(int a, int b) {
        const auto& check = [](int x) {
            int lookup = 0;
            for (; x; x /= 10) {
                if (lookup & (1 << (x % 10))) {
                    return false;
                }
                lookup |= 1 << (x % 10);
            }
            return true;
        };

        int result = 0;
        for (; a <= b; ++a) {
            result += check(a);
        }
        return result;
    }
};
