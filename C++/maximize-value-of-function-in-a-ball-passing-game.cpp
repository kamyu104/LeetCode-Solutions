// Time:  O(nlogk)
// Space: O(nlogk)

// binary lifting
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        const auto& bit_length = [](const auto& x) {
            return x != 0 ? 8 * sizeof(k) - __builtin_clzll(x) : 1;
        };

        const int l = bit_length(k + 1);
        vector<vector<int>> P(l, vector<int>(size(receiver)));
        P[0] = receiver;
        vector<vector<int64_t>> S(l, vector<int64_t>(size(receiver)));
        iota(begin(S[0]), end(S[0]), 0);
        for (int i = 1; i < l; ++i) {
            for (int u = 0; u < size(receiver); ++u) {
                P[i][u] = P[i - 1][P[i - 1][u]];
                S[i][u] = S[i - 1][u] + S[i - 1][P[i - 1][u]];
            }
        }
        int64_t result = 0;
        for (int u = 0; u < size(receiver); ++u) {
            int64_t curr = 0;
            for (int i = 0, v = u; i < l; ++i) {
                if ((k + 1) & (1ll << i)) {
                    curr += S[i][v];
                    v = P[i][v];
                }
            }
            result = max(result, curr);
        }
        return result;
    }
};
