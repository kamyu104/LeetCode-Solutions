// Time:  O(nlogn)
// Space: O(n)

// ntt, convolution
const int MOD = 998244353;
const int G = 3;

int64_t powmod(int a, int b) {
    a %= MOD;
    int64_t result = 1;
    while (b) {
        if (b & 1) {
            result = result * a % MOD;
        }
        a = int64_t(a) * a % MOD;
        b >>= 1;
    }
    return result;
};

void ntt(vector<int>& a, bool invert) {
    int n = size(a);
    int j = 0;
    for (int i = 1; i < n; ++i) {
        int bit = n >> 1;
        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    for (int length = 2; length <= n; length <<= 1) {
        int64_t wlen = powmod(G, (MOD - 1) / length);
        if (invert) {
            wlen = powmod(wlen, MOD - 2);
        }
        int half = length >> 1;
        for (int i = 0; i < n; i += length) {
            int64_t w = 1;
            for (int j = 0; j < half; ++j) {
                int u = a[i + j];
                int v = a[i + j + half] * w % MOD;
                int x = u + v;
                if (x >= MOD) {
                    x -= MOD;
                }
                int y = u - v;
                if (y < 0) {
                    y += MOD;
                }
                a[i + j] = x;
                a[i + j + half] = y;
                w = w * wlen % MOD;
            }
        }
    }
    if (invert) {
        int64_t inv_n = powmod(n, MOD - 2);
        for (int i = 0; i < n; ++i) {
            a[i] = a[i] * inv_n % MOD;
        }
    }
}

class Solution {
public:
    int minOperations(string s) {
        const auto& n = size(s);
        int sz = 1;
        while (sz < 2 * n - 1) {
            sz <<= 1;
        }
        vector<int> cost(n);
        for (int k = 0; k < 13; ++k) {
            vector<int> a(sz);
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                const auto& d = (((s[i] - 'a') - k) + 26) % 26;
                if (d >= 13) {
                    continue;
                }
                a[i] = 1;
                ++cnt;
            }
            ntt(a, false);
            for (int i = 0; i < size(a); ++i) {
                a[i] = static_cast<int64_t>(a[i]) * a[i] % MOD;
            }
            ntt(a, true);
            for (int c = 0; c < n; ++c) {
                cost[c] += cnt - (a[c] + (c + n < size(a) ? a[c + n] : 0));
            }
        }
        int result = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            result = min(result, i + cost[(2 * i - 1 + n) % n]);
        }
        return result;
    }
};
