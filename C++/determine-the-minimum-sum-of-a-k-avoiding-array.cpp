// Time:  O(1)
// Space: O(1)

// constructive algorithms, math
class Solution {
public:
    int minimumSum(int n, int k) {
        const auto& arithmetic_progression_sum  = [](const auto& a, const auto& d, const auto& n) {
            return (a + (a + (n - 1) * d)) * n / 2;
        };

        const auto a = min(k / 2, n), b = n - a;
        return arithmetic_progression_sum(1, 1, a) + arithmetic_progression_sum(k, 1, b);
    }
};
