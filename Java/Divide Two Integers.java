class Solution {
    public int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        }
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        boolean sign = (dividend> 0 && divisor > 0) || (dividend< 0 && divisor< 0);
        dividend= dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        int ans = 0;
        while (dividend <= divisor) {
            int x = divisor;
            int cnt = 1;
            while (x >= (Integer.MIN_VALUE >> 1) && dividend <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            dividend-= x;
        }
        return sign ? ans : -ans;
    }
}
