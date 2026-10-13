// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    bool threeFibonacciSum(int n) {
        if (n % 2) {
            return false;
        }
        int a = 1, b = 1;
        while (b < n / 2) {
            tie(a, b) = pair(b, a + b);
        }
        return b == n / 2;
    }
};
