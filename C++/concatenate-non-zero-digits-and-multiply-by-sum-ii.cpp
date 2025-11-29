// Time:  O(n)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        static const int MOD = 1e9 + 7;

        vector<int> pow10(size(s) + 1);
        pow10[0] = 1;
        vector<int> idx(size(s) + 1);
        vector<int> x(size(s) + 1);
        vector<int> total(size(s) + 1);
        for (int i = 0; i < size(s); ++i) {
            const auto& d = s[i] - '0';
            pow10[i + 1] = (pow10[i] * 10ll) % MOD;
            idx[i + 1] = idx[i] + (d ? 1 : 0);
            x[i + 1] = d ? (x[i] * 10ll + d) % MOD : x[i];
            total[i + 1] = total[i] + d;
        }
        vector<int> result(size(queries));
        for (int i = 0; i < size(queries); ++i) {
            const auto& l = queries[i][0], r = queries[i][1];
            result[i] = ((((x[r + 1] - static_cast<int64_t>(x[l]) * pow10[idx[r + 1] - idx[l]]) % MOD + MOD) % MOD) * (total[r + 1] - total[l])) % MOD;
        }
        return result;
    }
};
