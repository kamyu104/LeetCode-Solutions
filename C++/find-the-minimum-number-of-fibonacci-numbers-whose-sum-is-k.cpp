// Time:  O(logk)
// Space: O(1)

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int result = 0, a = 1, b = 1;
        while (b <= k) {
            tie(b, a) = pair(a + b, b);
        }
        while (k) {
            if (a <= k) {
                k -= a;
                ++result;
            }
            tie(a, b) = pair(b - a, a);
        }
        return result;
    }
};
