// Time:  O(n)
// Space: O(1)

// combinatorics, fast exponentiation
class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        // 2^(odd-1)*2^even = 2^(len(nums)-1)
        return any_of(cbegin(nums), cend(nums), [](const auto& x) {
            return x % 2 == 1;
        }) ? powmod(2, size(nums) - 1, MOD) : 0;
    }

private:
    uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
        a %= mod;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = result * a % mod;
            }
            a = uint64_t(a) * a % mod;
            b >>= 1;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// dp
class Solution2 {
public:
    int subsequenceCount(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        vector<int> dp(2);
        for (const auto& x : nums) {
            vector<int> new_dp(2);
            for (int i = 0; i < 2; ++i) {
                new_dp[i] = (dp[i] + dp[i ^ (x % 2)] + (x % 2 == i ? 1 : 0)) % MOD;
            }
            dp = move(new_dp);
        }
        return dp[1];
    }
};
