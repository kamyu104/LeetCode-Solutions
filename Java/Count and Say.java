class Combinations {
    long[] fact;
    long[] invFact;
    long M;

    public Combinations(int n, long mod) {
        M = mod;
        fact = new long[n + 1];
        invFact = new long[n + 1];
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % M;
            invFact[i] = power(fact[i], M - 2);
        }
    }

    long power(long base, long exp) {
        long res = 1;
        base %= M;
        while (exp > 0) {
            if ((exp & 1) == 1) res = (res * base) % M;
            base = (base * base) % M;
            exp >>= 1;
        }
        return res;
    }

    long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        long num = fact[n];
        long den = (invFact[r] * invFact[n - r]) % M;
        return (num * den) % M;
    }
}

class Solution {
    private static final int MOD = 1_000_000_007;

    public int idealArrays(int n, int maxValue) {
        Combinations comb = new Combinations(n, MOD);
        long[] dp = new long[maxValue + 1];
        long totalAns = maxValue;

        for (int i = 1; i <= maxValue; i++) {
            dp[i] = 1;
        }

        int kLimit = Math.min(n, 16);

        for (int k = 2; k <= kLimit; k++) {
            long[] next_dp = new long[maxValue + 1];
            for (int j = 1; j <= maxValue; j++) {
                if (dp[j] == 0) continue;
                for (long i = 2L * j; i <= maxValue; i += j) {
                    next_dp[(int) i] = (next_dp[(int) i] + dp[j]) % MOD;
                }
            }

            long count = 0;
            for (int i = 1; i <= maxValue; i++) {
                count = (count + next_dp[i]) % MOD;
            }

            if (count == 0) break;

            long factor = comb.nCr(n - 1, k - 1);
            totalAns = (totalAns + count * factor % MOD) % MOD;

            dp = next_dp;
        }

        return (int) totalAns;
    }
}