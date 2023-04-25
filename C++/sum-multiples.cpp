// Time:  O(1)
// Space: O(1)

// math, principle of inclusion and exclusion
class Solution {
public:
    int sumOfMultiples(int n) {
        const auto& f = [&](int d) {
            return d * (1 + (n / d)) * (n / d) / 2;
        };

        return (f(3) + f(5) + f(7)) - (f(3 * 5) + f(5 * 7) + f(7 * 3)) + f(3 * 5 * 7);
    }
};
