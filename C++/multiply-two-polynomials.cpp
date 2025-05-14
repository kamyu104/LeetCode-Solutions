// Time:  O((n + m) * log(n + m))
// Space: O(n + m)

const double PI = acos(-1.0);

void fft(vector<complex<double>>& a, bool invert) {
    const int n = size(a);
    if (n <= 1) {
      return;
    }

    // bit-reversal permutation
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    // Cooley-Tukey fft
    for (int len = 2; len <= n; len <<= 1) {
        double angle = 2 * PI / len * (invert ? -1 : 1);
        complex<double> wlen(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            complex<double> w(1);
            for (int j = 0; j < len / 2; ++j) {
                complex<double> u = a[i + j];
                complex<double> v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    // if inverse fft, divide by n
    if (invert) {
        for (complex<double>& x : a) {
            x /= n;
        }
    }
}

vector<long long> conv(const auto& poly1, const auto& poly2) {
    const int n = size(poly1), m = size(poly2);
    int sz = 1, tot = n + m - 1;
    while (sz < tot) {
        sz <<= 1;
    }
    vector<complex<double>> a(sz), b(sz);
    for (int i = 0; i < n; ++i) {
        a[i] = poly1[i];
    }
    for (int i = 0; i < m; ++i) {
        b[i] = poly2[i];
    }
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < sz; ++i) {
        a[i] *= b[i];
    }
    fft(a, true);
    vector<long long> result(tot);
    for (int i = 0; i < size(result); ++i) {
        result[i] = static_cast<long long>(round(a[i].real()));
    }
    return result;
}

// fft
class Solution {
public:
    vector<long long> multiply(vector<int>& poly1, vector<int>& poly2) {
        return conv(poly1, poly2);
    }
};
