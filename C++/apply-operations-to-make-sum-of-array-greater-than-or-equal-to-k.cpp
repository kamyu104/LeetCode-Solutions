// Time:  O(logn)
// Space: O(1)

// math
class Solution {
public:
    int minOperations(int k) {
        const auto& ceil_divide = [](const auto& a, const auto&b) {
            return (a + b - 1) / b;
        };

        const int x = sqrt(k);
        return (x - 1) + (ceil_divide(k, x) - 1);
    }
};
