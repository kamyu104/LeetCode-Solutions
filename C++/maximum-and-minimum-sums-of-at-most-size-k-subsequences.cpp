// Time:  O(nlogn)
// Space: O(n)

// sort, combinatorics, two pointers, sliding window
static const uint32_t MOD = 1e9 + 7;

uint32_t addmod(uint32_t a, uint32_t b) {  // avoid overflow
    if (MOD - a <= b) {
        b -= MOD;  // relied on unsigned integer overflow in order to give the expected results
    }
    return a + b;
}

uint32_t submod(uint32_t a, uint32_t b) {
    return addmod(a, (MOD - b) % MOD);
}

// reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
uint32_t mulmod(uint32_t a, uint32_t b)  {  // avoid overflow
    uint32_t result = 0;
    if (a < b) {
        swap(a, b);
    }
    while (b > 0)  { 
        if (b & 1) {
            result = addmod(result, a);
        }
        a = addmod(a, a);
        b >>= 1;
    } 
    return result; 
} 

vector<int> FACT = {1, 1};
vector<int> INV = {1, 1};
vector<int> INV_FACT = {1, 1};
int nCr(int n, int k) {
    if (n < k) {
        return 0;
    }
    while (size(INV) <= n) {  // lazy initialization
        FACT.emplace_back(mulmod(FACT.back(), size(INV)));
        INV.emplace_back(mulmod(INV[MOD % size(INV)], MOD - MOD / size(INV)));  // https://cp-algorithms.com/algebra/module-inverse.html
        INV_FACT.emplace_back(mulmod(INV_FACT.back(), INV.back()));
    }
    return mulmod(mulmod(FACT[n], INV_FACT[n - k]), INV_FACT[k]);
}

class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int result = 0;
        for (int i = 0, cnt = 1; i < size(nums); ++i) {
            result = addmod(result, mulmod(addmod(nums[i], nums[size(nums) - 1 - i]), cnt));
            cnt = submod(mulmod(cnt, 2), nCr(i, k - 1));
        }
        return result;
    }
};

// Time:  O(nlogn + n * k)
// Space: O(n)
// combinatorics
class Solution2 {
public:
    int minMaxSums(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            int cnt = 0;
            for (int j = 0; j <= min(i, k - 1); ++j) {
                cnt = addmod(cnt, nCr(i, j));
            }
            result = addmod(result, mulmod(addmod(nums[i], nums[size(nums) - 1 - i]), cnt));
        }
        return result;
    }
};
