// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numberOfWays(int num_people) {
        static const int MOD = 1e9 + 7;
        int n = num_people / 2;
        return 1ULL * nCr(2 * n, n, MOD) * inv(n + 1, MOD) % MOD;  // Catalan number
    }
    
private:
    int nCr(int n, int k, int m) {
        if (n - k < k) {
            return nCr(n, n - k, m);
        }
        uint64_t result = 1;
        for (int i = 1; i <= k; ++i) {
            result = (result * (n - k + i) % m) * inv(i, m) % m;
        }
        return result;
    }
    
    int inv(int x, int m) {  // Euler's Theorem
        return pow(x, m - 2, m);
    }

    int pow(uint64_t a, int b, int m) {  // O(logMOD) = O(1)
        a %= m;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution2 {
public:
    int numberOfWays(int num_people) {
        static const int MOD = 1e9 + 7;
        vector<uint64_t> dp(num_people / 2 + 1);
        dp[0] = 1ULL;
        for (int k = 1; k <= num_people / 2; ++k) {
            for (int i = 0; i < k; ++i) {
                dp[k] = (dp[k] + dp[i] * dp[k - 1 - i]) % MOD;
            }
        }
        return dp[num_people / 2];
    }
};
