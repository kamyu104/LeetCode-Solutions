class Solution {

    public String findLexSmallestString(String s, int a, int b) {
        int n = s.length();
        String res = s;
        s = s + s;
        int g = gcd(b, n);
        for (int i = 0; i < n; i += g) {
            for (int j = 0; j < 10; j++) {
                int kLimit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= kLimit; k++) {
                    char[] t = s.substring(i, i + n).toCharArray();
                    for (int p = 1; p < n; p += 2) {
                        t[p] = (char) ('0' + ((t[p] - '0' + j * a) % 10));
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = (char) ('0' + ((t[p] - '0' + k * a) % 10));
                    }
                    String tStr = new String(t);
                    if (tStr.compareTo(res) < 0) {
                        res = tStr;
                    }
                }
            }
        }
        return res;
    }

    public int gcd(int num1, int num2) {
        while (num2 != 0) {
            int temp = num1;
            num1 = num2;
            num2 = temp % num2;
        }
        return num1;
    }
}
