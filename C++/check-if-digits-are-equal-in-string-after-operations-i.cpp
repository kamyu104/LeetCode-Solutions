// Time:  O(nlogn)
// Space: O(1)

// fast exponentiation
class Solution {
public:
    bool hasSameDigits(string s) {
        const auto& pow = [](uint64_t a, int b, int m) {  // O(logMOD) = O(1)
            a %= m;
            uint64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = (result * a) % m;
                }
                a = (a * a) % m;
                b >>= 1;
            }
            return result;
        };

        const auto& check = [&](int mod) {
            const auto& decompose = [](int x, int mod) {  // x = a * mod^cnt
                int cnt = 0;
                while (x > 1 && x % mod == 0) {
                    x /= mod;
                    ++cnt;
                }
                return pair(x, cnt);
            };

            int result = 0, cnt = 0;
            int curr = 1;
            for (int i = 0; i <= size(s) - 2; ++i) {
                if (cnt == 0) {
                    result = (result + curr * (s[i] - s[i + 1])) % mod;
                }
                const auto& [x1, c1] = decompose(size(s) - 2 - i, mod);
                curr = (curr * x1) % mod;
                cnt += c1;
                const auto& [x2, c2] = decompose(i + 1, mod);
                curr = (curr * pow(x2, mod - 2, mod)) % mod;
                cnt -= c2;
            }
            return result == 0;
        };

        return check(2) && check(5);
    }
};

// Time:  O(nlogn)
// Space: O(1)
vector<vector<int>> LOOKUP(5 + 1, vector<int>(5 + 1, -1));

// lucas's theorem
class Solution2 {
public:
    bool hasSameDigits(string s) {
        const auto& nCr = [&](int n, int r) {
            if (n - r < r) {
                r = n - r;
            }
            if (LOOKUP[n][r] == -1) {
                int c = 1;
                for (int k = 1; k <= r; ++k) {
                    c *= n - k + 1;
                    c /= k;
                }
                LOOKUP[n][r] = c;
            }
            return LOOKUP[n][r];
        };

        // https://en.wikipedia.org/wiki/Lucas%27s_theorem
        const auto& nCr_mod = [&](int n, int r, int mod) {
            int result = 1;
            while (n > 0 || r > 0) {
                const int ni = n % mod;
                n /= mod;
                const int ri = r % mod;
                r /= mod;
                if (ni < ri) {
                    return 0;
                }
                result = (result * nCr(ni, ri)) % mod;
            }
            return result;
        };

        vector<vector<int>> lookup(2, vector<int>(5));
        for (int i = 0; i < 10; ++i) {
            lookup[i % 2][i % 5] = i;
        }
        const auto& nC10 = [&](int n, int k) {
            return lookup[nCr_mod(n, k, 2)][nCr_mod(n, k, 5)];
        };

        int total = 0;
        for (int i = 0; i <= size(s) - 2; ++i) {
            total = (total + nC10(size(s) - 2, i) * (((s[i] - s[i + 1]) % 10 + 10) % 10)) % 10;
        }
        return total == 0;
    }
};

// Time:  O(n^2)
// Space: O(1)
// simulation
class Solution3 {
public:
    bool hasSameDigits(string s) {
        for (int l = size(s); l >= 3; --l) {
            for (int i = 0; i + 1 < l; ++i) {
                s[i] = '0' + ((s[i] - '0') + (s[i + 1] - '0')) % 10;
            }
        }
        return s[0] == s[1];
    }
};
