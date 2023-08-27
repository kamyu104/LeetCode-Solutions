// Time:  O(1)
// Space: O(1)

// constructive algorithms, math
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        const auto& arithmetic_progression_sum  = [](const int64_t a, const int64_t d, const int64_t n) {
            return (a + (a + (n - 1) * d)) * n / 2;
        };

        const auto a = min(target / 2, n), b = n - a;
        return arithmetic_progression_sum(1, 1, a) + arithmetic_progression_sum(target, 1, b);
    }
};
