// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    bool checkDivisibility(int n) {
        int total = 0, product = 1;
        for (int curr = n; curr; curr /= 10) {
            total += curr % 10;
            product *= curr % 10;
        }
        return n % (total + product) == 0;
    }
};
