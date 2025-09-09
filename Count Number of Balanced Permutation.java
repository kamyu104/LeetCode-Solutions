class Solution {

    private static final long MOD = 1_000_000_007;

    public int countBalancedPermutations(String num) {
        int tot = 0, n = num.length();
        int[] cnt = new int[10];
        for (char ch : num.toCharArray()) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        long[][] comb = new long[maxOdd + 1][maxOdd + 1];
        long[][] f = new long[target + 1][maxOdd + 1];

        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        f[0][0] = 1;
        int psum = 0, totSum = 0;
        for (int i = 0; i <= 9; i++) {
            /* Sum of the number of the first i digits */
            psum += cnt[i];
            /* Sum of the first i numbers */
            totSum += i * cnt[i];
            for (
                int oddCnt = Math.min(psum, maxOdd);
                oddCnt >= Math.max(0, psum - (n - maxOdd));
                oddCnt--
            ) {
                /* The number of bits that need to be filled in even numbered positions */
                int evenCnt = psum - oddCnt;
                for (
                    int curr = Math.min(totSum, target);
                    curr >= Math.max(0, totSum - target);
                    curr--
                ) {
                    long res = 0;
                    for (
                        int j = Math.max(0, cnt[i] - evenCnt);
                        j <= Math.min(cnt[i], oddCnt) && i * j <= curr;
                        j++
                    ) {
                        /* The current digit is filled with j positions at odd positions, and cnt[i] - j positions at even positions */
                        long ways =
                            (comb[oddCnt][j] * comb[evenCnt][cnt[i] - j]) % MOD;
                        res =
                            (res +
                                ((ways * f[curr - i * j][oddCnt - j]) % MOD)) %
                            MOD;
                    }
                    f[curr][oddCnt] = res % MOD;
                }
            }
        }

        return (int) f[target][maxOdd];
    }
}
