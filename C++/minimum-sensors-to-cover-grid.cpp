// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int minSensors(int n, int m, int k) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        return static_cast<int64_t>(ceil_divide(n, 2 * k + 1)) * ceil_divide(m, 2 * k + 1);
    }
};
