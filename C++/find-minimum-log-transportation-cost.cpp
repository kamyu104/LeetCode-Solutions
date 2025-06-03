// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        return static_cast<long long>(k) * max({n - k, m - k, 0});
    }
};
