// Time:  O(logn * nlogx * logx) = O(1)
// Space: O(nlogx) = O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long abs_n = abs(static_cast<long>(n));
        while (abs_n > 0) {
            if (abs_n & 1) {
                res *= x;
            }
            abs_n >>= 1;
            x *= x;
        }
        return n < 0 ?  1 / res : res;
    }
};

// Time:  O(logn * nlogx * logx) = O(1)
// Space: O(nlogx) = O(1)
// Recursive solution.
class Solution2 {
public:
    double myPow(double x, int n) {
        if (n < 0 && n != -n) {
            return 1.0 / myPow(x, -n);
        }
        if (n == 0) {
            return 1;
        }
        double v = myPow(x, n / 2);
        if (n % 2 == 0) {
            return v * v;
        } else {
            return v * v * x;
        }
    }
};
