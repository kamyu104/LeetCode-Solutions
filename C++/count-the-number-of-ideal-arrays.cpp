// Time:  O(n * mlogm)
// Space: O(n + m)

// dp, combinatorics
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        int result = 0;
        unordered_map<int, int> dp;
        for (int i = 1; i <= maxValue; ++i) {
            dp[i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> new_dp;
            int total = 0;
            for (const auto& [x, c] : dp) {
                total = addmod(total, c);
                for (int y = x + x; y <= maxValue; y += x) {
                    new_dp[y] += c;
                }
            }
            result = addmod(result, mulmod(total , nCr(n - 1, i)));
            dp = move(new_dp);
        }
        return result;
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
