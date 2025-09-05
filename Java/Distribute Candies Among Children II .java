class Solution {
    public long distributeCandies(int n, int limit) {
        java.util.function.LongUnaryOperator C2 = x -> (x >= 2) ? (x * (x - 1) / 2) : 0L;
        long N = n, L = limit;
        long total = (N + 2) * (N + 1) / 2;
        long x1 = N - L + 1; 
        long t1 = C2.applyAsLong(x1);
        long x2 = N - 2 * L;
        long t2 = C2.applyAsLong(x2);
        long x3 = N - 3 * L - 1;
        long t3 = C2.applyAsLong(x3);
        return total - 3 * t1 + 3 * t2 - t3;
    }
}
