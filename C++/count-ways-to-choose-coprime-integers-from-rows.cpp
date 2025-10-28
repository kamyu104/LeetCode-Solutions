// Time:  O(n * (m + rlogr)), r = max(max(row) for row in mat)
// Space: O(r)

// dp, number theory, mobius function, principle of inclusion-exclusion
class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        static const int MOD = 1e9 + 7;

        const auto& linear_sieve_of_eratosthenes = [](int n) {  // Time: O(n), Space: O(n)
            vector<int> spf(n + 1, -1);
            vector<int> primes;
            for (int i = 2; i <= n; ++i) {
                if (spf[i] == -1) {
                    spf[i] = i;
                    primes.emplace_back(i);
                }
                for (const auto& p : primes) {
                    if (i * p > n || p > spf[i]) {
                        break;
                    }
                    spf[i * p] = p;
                }
            }
            return spf;
        };

        // https://www.geeksforgeeks.org/program-for-mobius-function-set-2/
        const auto& mobius = [](const auto& spf) {  // Time: O(n), Space: O(n)
            vector<int> mu(size(spf));
            for (int i = 1; i < size(mu); ++i) {
                mu[i] = i == 1 ? 1 : (spf[i / spf[i]] == spf[i] ? 0 :  -mu[i / spf[i]]);
            }
            return mu;
        };

        int mx = 0;
        for (const auto& row : mat) {
            mx = max(mx, ranges::max(row));
        }
        const auto& mu = mobius(linear_sieve_of_eratosthenes(mx));
        vector<int64_t> dp(mx + 1, 1);
        for (const auto& row : mat) {
            unordered_map<int, int> cnt;
            for (const auto& x : row) {
                ++cnt[x];
            }
            for (int i = 1; i <= mx; ++i) {
                int total = 0;
                for (int j = i; j <= mx; j += i) {
                    total = (total + cnt[j]) % MOD;
                }
                dp[i] = (dp[i] * total) % MOD;
            }            
        }
        int result = 0;
        for (int i = 1; i <= mx; ++i) {
            result = (result + (((dp[i] * mu[i]) % MOD + MOD) % MOD)) % MOD;
        }
        return result;
    }
};


// Time:  O(n * m * rlogr)
// Space: O(r)
// dp, number theory
class Solution2 {
public:
    int countCoprime(vector<vector<int>>& mat) {
        static const int MOD = 1e9 + 7;

        unordered_map<int, int> dp;
        dp[0] = 1;
        for (const auto& row : mat) {
            unordered_map<int, int> new_dp;
            for (const auto& x : row) {
                for (const auto& [g, c] : dp) {
                    const auto& ng = gcd(g, x);
                    new_dp[ng] = (new_dp[ng] + c) % MOD;
                }
            }
            dp = move(new_dp);
        }
        return dp[1];
    }
};
