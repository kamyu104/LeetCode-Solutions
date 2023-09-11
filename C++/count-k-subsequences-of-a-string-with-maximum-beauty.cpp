// Time:  O(n)
// Space: O(1)

// greedy, quick select, combinatorics
class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<int, int> cnt;
        for (const auto& c : s) {
            ++cnt[c];
        }
        if (size(cnt) < k) {
            return 0;
        }
        vector<int> freqs;
        freqs.reserve(26);
        for (const auto& [_, v] : cnt) {
            freqs.emplace_back(v);
        }
        nth_element(begin(freqs), begin(freqs) + (k - 1), end(freqs), greater<int>());
        int result = 1;
        for (int i = 0; i < k; ++i) {
            result = mulmod(result, freqs[i]);
        }
        const int n = count(cbegin(freqs), cend(freqs), freqs[k - 1]);
        const int r = count(cbegin(freqs), cbegin(freqs) + k, freqs[k - 1]);
        return mulmod(result, nCr(n, r));
    }

private:
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
