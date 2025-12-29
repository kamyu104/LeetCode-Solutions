// Time:  O(k)
// Space: O(1)

// math, leetcode #1015
class Solution {
public:
    int minAllOneMultiple(int k) {
        // by observation, k % 2 = 0 or k % 5 = 0, it is impossible
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        // let f(n) is a n-length integer only containing digit 1
        // given k % 2 != 0 and k % 5 != 0
        // if there is no n in range (1..k) s.t. f(n) % k = 0
        // => there must be k remainders of f(n) % k in range (1..k-1) excluding 0
        // => due to pigeonhole principle, there must be at least 2 same remainders
        // => there must be some x, y in range (1..k) and x > y s.t. f(x) % k = f(y) % k
        // => (f(x) - f(y)) % k = 0
        // => (f(x-y) * 10^y) % k = 0
        // => due to (x-y) in range (1..k)
        // => f(x-y) % k != 0
        // => 10^y % k = 0
        // => k % 2 = 0 or k % 5 = 0
        // => -><-
        // it proves that there must be some n in range (1..k) s.t. f(n) % k = 0
        int r = 0;
        for (int n = 1; n <= k; ++n) {
            r = (r * 10 + 1) % k;
            if (!r) {
                return n;
            }
        }
        assert(false);
        return -1;  // never reach
    }
};
