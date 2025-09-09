class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        final int MOD = 1_000_000_007;
        if (n == 1) return 1;
        long[] dp = new long[n + 1];
        dp[1] = 1;
        long window = 0;
        for (int i = 2; i <= n; i++) {
            int enter = i - delay;
            int exit  = i - forget;
            if (enter >= 1) window = (window + dp[enter]) % MOD;
            if (exit  >= 1) window = (window - dp[exit] + MOD) % MOD;
            dp[i] = window;
        }
        long ans = 0;
        int start = Math.max(1, n - forget + 1);
        for (int i = start; i <= n; i++) ans = (ans + dp[i]) % MOD;
        return (int)ans;
    }
}
