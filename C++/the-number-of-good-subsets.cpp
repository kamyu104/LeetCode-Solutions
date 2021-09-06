// Time:  O(n * 2^p), p is the number of primes in [1, n]
// Space: O(2^p)

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        static const int MOD = 1e9 + 7;
        const auto& primes = sieve_of_eratosthenes(*max_element(cbegin(nums), cend(nums)));
        vector<int> dp(1 << size(primes));  // dp[i] = the number of different good subsets of which the total product equals to the product of the primes in bitset i
        dp[0] = 1;
        unordered_map<int, int> cnts;
        for (const auto& x : nums) {
            ++cnts[x];
        }
        for (const auto& [x, cnt] : cnts) {
            if (x == 1 || any_of(cbegin(primes), cend(primes), [&x=x](const auto& p) { return p * p <= x && x % (p * p) == 0;} )) {  // [&x=x] is to avoid the problem that lambda function captures variables declared from structured binding
                continue;
            }
            const uint32_t mask = to_mask(primes, x);
            for (int i = 0; i < size(dp) - 1; ++i) {
                if (i & mask) {
                    continue;
                }
                dp[i | mask] = (dp[i | mask] + static_cast<uint64_t>(cnt) * dp[i]) % MOD;
            }
        }
        return powmod(2, cnts[1], MOD) * (accumulate(cbegin(dp), cend(dp), 0ull,
                                                     [](const auto& total, const auto& x) {
                                                         return (total + x) % MOD;
                                                     }) - 1) % MOD;
    }

private:
    vector<int> sieve_of_eratosthenes(int n) {  // Time: O(n * log(logn)), Space: O(n)
        if (n < 2) {
            return {};
        }
        vector<int> primes = {2};
        vector<bool> is_prime((n + 1) / 2, true);
        for (int i = 1; i < size(is_prime); ++i) {
            if (!is_prime[i]) {
                continue;
            }
            primes.emplace_back(2 * i + 1);
            for (int j = 2 * i * (i + 1); j < size(is_prime); j += (2 * i + 1)) {
                is_prime[j] = false;
            }
        }
        return primes;
    }

    uint32_t to_mask(const vector<int>& primes, int x) {
        uint32_t mask = 0, basis = 1;
        for (const auto& p : primes) {
            if (x % p == 0) {
                mask |= basis;
            }
            basis <<= 1;
        }
        return mask;
    }

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
