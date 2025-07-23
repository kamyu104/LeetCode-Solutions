// Time:  precompute: O((logr)^2), r = max(n)
//        runtime:    O((logn)^2)
// Space: O((logr)^2)

// combinatorics
int bit_length(int64_t x) {
    return (x ? std::__lg(x) : -1) + 1;
}

pair<vector<vector<int64_t>>, vector<int>> init() {
    static const int64_t MAX_N = 1e15;
    static const int MAX_BIT_LEN = bit_length(MAX_N);
    vector<vector<int64_t>> NCR(MAX_BIT_LEN + 1, vector<int64_t>(MAX_BIT_LEN + 1));
    for (int i = 0; i < size(NCR); ++i) {
        for (int j = 0; j <= i; ++j) {
            NCR[i][j] = 0 < j && j < i ? NCR[i - 1][j] + NCR[i - 1][j - 1] : 1;
        }
    }
    vector<int> D(MAX_BIT_LEN + 1, 0);
    for (int i = 2; i < size(D); ++i) {
        D[i] = D[__builtin_popcount(i)] + 1;
    }
    return {NCR, D};
}

const auto& [NCR, D] = init();
class Solution {
public:
    long long popcountDepth(long long n, int k) {
        if (k == 0) {
            return 1;
        }
        const int l = bit_length(n);
        if (k == 1) {
            return l - 1;
        }
        const auto& count = [&](int c) {
            int64_t result = 0;
            int cnt = 0;
            for (int i = l - 1; i >= 0; --i) {
                if (!(n & (1ll << i))) {
                    continue;
                }
                if (0 <= c - cnt && c - cnt <= i) {
                    result += NCR[i][c - cnt];
                }
                ++cnt;
            }
            if (cnt == c) {
                ++result;
            }
            return result;
        };

        int64_t result = 0;
        for (int c = 2; c <= l; ++c) {
            if (D[c] == k - 1) {
                result += count(c);
            }
        }
        return result;
    }
};
