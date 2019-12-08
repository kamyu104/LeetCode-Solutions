// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, total = 0;
        for (; n; n /= 10) {
            product *= n % 10;
            total += n % 10;
        }
        return product - total;
    }
};
