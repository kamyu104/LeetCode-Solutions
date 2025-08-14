class Solution {
    // Count digit frequencies of a non-negative integer n
    private int[] digitFreq(int n) {
        int[] freq = new int[10];
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
        return freq;
    }

    // Compare two frequency arrays (length 10)
    private boolean equalFreq(int[] a, int[] b) {
        for (int i = 0; i < 10; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    public boolean reorderedPowerOf2(int N) {
        int[] target = digitFreq(N);

        // Check all powers of two up to 2^30 (fits in 32-bit signed int ie till limit ie 10^9)
        for (int i = 0; i <= 30; i++) {
            int powerof2 = (int) Math.pow(2, i); // 2^i
            if (equalFreq(target, digitFreq(powerof2)))
                return true;
        }
        return false;
    }
}
