// Time:  O(26 * n) = O(n)
// Space: O(max_n) = O(max_n)

class Solution {
public:
    int makeStringSorted(string s) {  // count of prev_permutation
        static const int MOD = 1e9 + 7;

        array<int, 26> count = {0};
        int result = 0, comb_total = 1;
        for (int i = size(s) - 1; i >= 0; --i) {
            int num = s[i] - 'a';
            comb_total = ((comb_total * int64_t(size(s) - i) % MOD) * inverse(++count[num], MOD)) % MOD;
            result = (result + ((comb_total * accumulate(cbegin(count), cbegin(count) + num, 0LL) % MOD) * inverse(size(s) - i, MOD) % MOD)) % MOD;
        }
        return result;
    }
private:
    int inverse(int n, int m) {
        static vector<int> inv = {0, 1};

        for (int i = size(inv); i <= n; ++i) {  // lazy initialization
            inv.emplace_back(inv[m % i] * int64_t(m - m / i) % m);  // https://cp-algorithms.com/algebra/module-inverse.html  
        }
        return inv[n];
    }
};
