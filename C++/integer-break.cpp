// Time:  O(logn), pow is O(logn).
// Space: O(logn)

class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }

        // Proof.
        // 1. Let n = a1 + a2 + ... + ak, product = a1 * a2 * ... * ak
        //     - For each ai >= 4, we can always maximize the product by:
        //       ai <= 2 * (ai - 2)
        //     - For each aj >= 5, we can always maximize the product by:
        //       aj <= 3 * (aj - 3)
        // 
        //    Conclusion 1:
        //     - For n >= 4, the max of the product must be in the form of
        //       3^a * 2^b, s.t. 3a + 2b = n
        //
        // 2. To maximize the product = 3^a * 2^b s.t. 3a + 2b = n
        //     - For each b >= 3,  we can always maximize the product by:
        //       3^a * 2^b <= 3^(a+2) * 2^(b-3) s.t. 3(a+2) + 2(b-3) = n
        //
        //    Conclusion 2:
        //     - For n >= 4, the max of the product must be in the form of
        //       3^Q * 2^R, 0 <= R < 3 s.t. 3Q + 2R = n
        //       i.e.
        //         if n = 3Q + 0,   the max of the product = 3^Q * 2^0
        //         if n = 3Q + 2,   the max of the product = 3^Q * 2^1
        //         if n = 3Q + 2*2, the max of the product = 3^Q * 2^2

        int res = 0;
        if (n % 3 == 0) {         // n = 3Q + 0, the max is 3^Q * 2^0
            res = pow(3, n / 3);
        } else if (n % 3 == 2) {  // n = 3Q + 2, the max is 3^Q * 2^1
            res =  pow(3, n / 3) * 2;
        } else {                  // n = 3Q + 4, the max is 3^Q * 2^2
            res = pow(3, n / 3 - 1) * 4;
        }
        return res;
    }
};
