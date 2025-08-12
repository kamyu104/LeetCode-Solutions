class Solution {
    private static final int MOD = 1_000_000_007;
    public int numberOfWays(int n, int x) {
        long[] dp = new long[n + 1];
        dp[0] = 1; 
        for (int i = 1; Math.pow(i, x) <= n; i++) {
            int power = (int) Math.pow(i, x);
            for (int sum = n; sum >= power; sum--) {
            dp[sum] = (dp[sum] + dp[sum - power]) % MOD;
            }
        } return (int) dp[n];
    }
}
