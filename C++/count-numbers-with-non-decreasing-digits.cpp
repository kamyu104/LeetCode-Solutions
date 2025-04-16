// Time:  O(n^2), n = len(r)
// Space: O(n)

// math, stars and bars, combinatorics
class Solution {
public:
    int countNumbers(string l, string r, int b) {
        const auto& decrease = [](auto& digits){
            for (int i = size(digits) - 1; i >= 0; --i) {
                if (digits[i]) {
                    --digits[i];
                    break;
                }
                digits[i] = 9;
            }
        };

        const auto& divide = [](const auto& digits, int base) {
            vector<uint8_t> result;
            result.reserve(size(digits));
            int r = 0;
            for (const auto& d : digits) {
                int q = (r * 10 + d) / base;
                r = (r * 10 + d) % base;
                if (!empty(result) || q) {
                    result.emplace_back(q);
                }
            }
            return pair(result, r);
        };

        const auto& to_digits = [](const auto& s) {
            vector<uint8_t> result(size(s));
            for (int i = 0; i < size(s); ++i) {
                result[i] = s[i] - '0';
            }
            return result;
        };

        const auto& to_base = [&](auto digits, int base) {
            vector<uint8_t> result;
            while (!empty(digits)) {
                auto [q, r] = divide(digits, base);
                result.emplace_back(r);
                digits = move(q);
            }
            reverse(begin(result), end(result));
            return result;
        };

        const auto& count = [&](const auto& digits) {
            const auto& digits_base = to_base(digits, b);
            int result = 0;
            int i = 0;
            for (; i < size(digits_base); ++i) {
                if (i - 1 >= 0 && digits_base[i - 1] > digits_base[i]) {
                    break;
                }
                for (int j = i - 1 >= 0 ? digits_base[i - 1] : 0; j < digits_base[i]; ++j) {
                    result = addmod(result, nHr((b - 1) - j + 1, size(digits_base) - (i + 1)));
                }
            }
            if (i == size(digits_base)) {
                result = addmod(result, 1);
            }
            return result;
        };

        auto digits_l = to_digits(l);
        decrease(digits_l);
        auto digits_r = to_digits(r);
        return submod(count(digits_r), count(digits_l));
    }

private:
    int nHr(int n, int k) {
        return nCr(n + k - 1, k);
    }

    int nCr(int n, int k) {
        while (size(inv_) <= n) {  // lazy initialization
            fact_.emplace_back(mulmod(fact_.back(), size(inv_)));
            inv_.emplace_back(mulmod(inv_[MOD % size(inv_)], MOD - MOD / size(inv_)));  // https://cp-algorithms.com/algebra/module-inverse.html
            inv_fact_.emplace_back(mulmod(inv_fact_.back(), inv_.back()));
        }
        return mulmod(mulmod(fact_[n], inv_fact_[n - k]), inv_fact_[k]);
    }

    uint32_t addmod(uint32_t a, uint32_t b) {  // avoid overflow
        a %= MOD, b %= MOD;
        if (MOD - a <= b) {
            b -= MOD;  // relied on unsigned integer overflow in order to give the expected results
        }
        return a + b;
    }

    uint32_t submod(uint32_t a, uint32_t b) {
        return addmod(a, (MOD - b) % MOD);
    }

    // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
    uint32_t mulmod(uint32_t a, uint32_t b)  {  // avoid overflow
        a %= MOD, b %= MOD;
        uint32_t result = 0;
        if (a < b) {
            swap(a, b);
        }
        while (b > 0)  {
            if (b % 2 == 1) {
                result = addmod(result, a);
            }
            a = addmod(a, a);
            b /= 2;
        }
        return result;
    }

    static const uint32_t MOD = 1e9 + 7;
    vector<int> fact_ = {1, 1};
    vector<int> inv_ = {1, 1};
    vector<int> inv_fact_ = {1, 1};
};
