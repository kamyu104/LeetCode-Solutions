// Time:  O(1)
// Space: O(1)

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // p(k) = 1 * (prob that 1th passenger takes his own seat) +
        //        0 * (prob that 1th passenger takes kth one's seat) +
        //        1 * (prob that 1th passenger takes the others' seat) * 
        //            (prob that the first k-1 passengers get a seat
        //             which is not kth one's seat)
        //        = 1/k + p(k-1)*(k-2)/k
        //    
        // p(1) = 1
        // p(2) = 1/2 + p(1) * (2-2)/2 = 1/2
        // p(3) = 1/3 + p(2) * (3-2)/3 = 1/3 + 1/2 * (3-2)/3 = 1/2
        // ...
        // p(n) = 1/n + 1/2 * (n-2)/n = (2+n-2)/(2n) = 1/2
        return n != 1 ? 0.5 : 1.0;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    double nthPersonGetsNthSeat(int n) {
        vector<double> dp(2);
        dp[0] = 1.0;  // zero-indexed
        for (int i = 2; i <= n; ++i) {
            dp[(i - 1) % 2] = 1.0 / i + dp[(i - 2) % 2] * (i - 2) / i;
        }
        return dp[(n - 1) % 2];
    }
};
