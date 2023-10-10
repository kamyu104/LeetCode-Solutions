// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int differenceOfSums(int n, int m) {
        return (n + 1) * n / 2 - 2 * (((n / m + 1) * (n / m) / 2) * m);
    }
};
