// Time:  O(logn) = O(1)
// Space: O(1)

// Only using integer type.
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle corner case.
        if (dividend == numeric_limits<int>::min() && divisor == -1) {
            return numeric_limits<int>::max();
        }

        int a = dividend > 0 ? -dividend : dividend;
        int b = divisor > 0 ? -divisor : divisor;

        int shift = 0;
        while (b << shift < 0 && shift < 32) {
            ++shift;
        }
        shift -= 1;

        int result = 0;
        while (shift >= 0) {
            if (a <= b << shift) {
                a -= b << shift;
                result += 1 << shift;
            }
            --shift;
        }

        result =  (dividend ^ divisor) >> 31 ? -result : result;
        return result;
    }
};

// Time:  O(logn) = O(1)
// Space: O(1)
// Using long long type.
class Solution2 {
public:
    int divide(int dividend, int divisor) {
        long long result = 0;
        long long a = llabs(dividend);
        long long b = llabs(divisor);

        int shift = 31;
        while (shift >= 0) {
            if (a >= b << shift) {
                a -= b << shift;
                result += 1LL << shift;
            }
            --shift;
        }

        result = ((dividend ^ divisor) >> 31) ? -result : result;
        return min(result, static_cast<long long>(numeric_limits<int>::max()));
    }
};

// Time:  O(logn) = O(1)
// Space: O(1)
// a / b = exp^(ln(a) - ln(b))
class Solution3 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) { 
            return 0;
        }
        if (divisor == 0) {
            return numeric_limits<int>::max();
        }

        long long result = exp(log(fabs(dividend)) - log(fabs(divisor)));

        result = ((dividend ^ divisor) >> 31) ? -result : result;
        return min(result, static_cast<long long>(numeric_limits<int>::max()));
    }
};
