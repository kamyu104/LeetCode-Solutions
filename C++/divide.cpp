// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
    public:
        int divide(int dividend, int divisor) {
            long long a = dividend >= 0 ? dividend : -(long long)dividend;
            long long b = divisor >= 0 ? divisor : -(long long)divisor;

            long long result = 0;
            while(a >= b) {
                long long c = b;
                int i = 0;
                for(; a >= c; c <<= 1, ++i);
                if(i > 0) {
                    a -= c >> 1;
                    result += 1 << (i - 1);
                }
            }

            return ((dividend ^ divisor) >> 31)? -result : result;
        }
};
