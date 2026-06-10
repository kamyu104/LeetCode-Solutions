// Time:  O(1)
// Space: O(1)

// math, invariant
class Solution {
public:
    long long minCost(int n) {
        return n * (n - 1LL) / 2;
    }
};
