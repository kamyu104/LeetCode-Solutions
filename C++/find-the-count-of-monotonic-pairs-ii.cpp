// Time:  O(n + r), r = max(nums)
// Space: O(n + r)

// combinatorics, stars and bars
class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        // arr1 = [0+x1, arr1[0]+max(nums[1]-nums[0], 0)+x2, ..., arr[n-2]+max(nums[n-1]-nums[n-2], 0)+xn]
        // => sum(max(nums[i]-nums[i-1], 0) for i in xrange(1, len(nums)))+(x1+x2+...+xn) <= nums[-1]
        // => x1+x2+...+xn <= nums[-1]-sum(max(nums[i]-nums[i-1], 0) for i in xrange(1, len(nums))) = cnt <= min(nums)
        // => the answer is the number of solutions s.t. x1+x2+...+xn <= cnt, where cnt >= 0
        int cnt = nums.back();
        for (int i = 1; i < size(nums); ++i) {
            cnt -= max(nums[i] - nums[i - 1], 0);
        }
        return cnt >= 0 ? nHr(size(nums) + 1, cnt) : 0;
    }

private:
    int nHr(int n, int r) {
        return nCr(n + r - 1, r);
    }

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
            if (b & 1) {
                result = addmod(result, a);
            }
            a = addmod(a, a);
            b >>= 1;
        } 
        return result; 
    }
   
    static const uint32_t MOD = 1e9 + 7;
    vector<int> fact_ = {1, 1};
    vector<int> inv_ = {1, 1};
    vector<int> inv_fact_ = {1, 1};
};

// Time:  O(n * r), r = max(nums)
// Space: O(r)
// dp, prefix sum
class Solution2 {
public:
    int countOfPairs(vector<int>& nums) {
        static const int MOD = 1e9 + 7;
        vector<int> dp(ranges::max(nums) + 1);  // dp[j]: numbers of arr1, which is of length i+1 and arr1[i] is j
        for (int i = 0; i <= nums[0]; ++i) {
            dp[i] = 1;
        }
        for (int i = 1; i < size(nums); ++i) {
            // arr1[i-1] <= arr1[i]
            // => arr1[i]-arr1[i-1] >= 0 (1)
            //
            // arr2[i-1] >= arr2[i]
            // => nums[i-1]-arr1[i-1] >= nums[i]-arr1[i] 
            // => arr1[i]-arr1[i-1] >= nums[i]-nums[i-1] (2)
            //
            // (1)+(2): arr1[i]-arr1[i-1] >= max(nums[i]-nums[i-1], 0)
            vector<int> new_dp(size(dp));
            const int diff = max(nums[i] - nums[i - 1], 0);
            for (int j = diff; j <= nums[i]; ++j) {
                new_dp[j] = ((j - 1 >= 0 ? new_dp[j - 1] : 0) + dp[j - diff]) % MOD;
            }
            dp = move(new_dp);
        }
        return accumulate(cbegin(dp), cend(dp), 0, [&](const auto& accu, const auto& x) {
            return (accu + x) % MOD;
        });
    }
};
