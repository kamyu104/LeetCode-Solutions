// Time:  O(n^2)
// Space: O(n^2)

// simulation, math
const int MOD = 1e9 + 7;
vector<int> FACT = {1, 1};
vector<int> INV = {1, 1};
vector<int> INV_FACT = {1, 1};
const auto& lazy_init = [](int n) {
    while (size(INV) <= n) {  // lazy initialization
        FACT.emplace_back((static_cast<int64_t>(FACT.back()) * size(INV)) % MOD);
        INV.emplace_back((static_cast<int64_t>(INV[MOD % size(INV)]) * (MOD - MOD / size(INV))) % MOD);  // https://cp-algorithms.com/algebra/module-inverse.html
        INV_FACT.emplace_back((static_cast<int64_t>(INV_FACT.back()) * INV.back()) % MOD);
    }
};

const auto& factorial = [](int n) {
    lazy_init(n);
    return FACT[n];
};

const auto& inv_factorial = [](int n) {
    lazy_init(n);
    return INV_FACT[n];
};

class Solution {
public:
    int sumOfBlocks(int n) {
        int result = 0;
        for (int l = 0, left = 1, right; l < n; ++l) {
            right = left + l;
            result = (result + ((static_cast<int64_t>(factorial(right)) * inv_factorial(left - 1)) % MOD)) % MOD;
            left = right + 1;
        }
        return result;
    }
};
