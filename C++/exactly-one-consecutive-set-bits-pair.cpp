// Time:  O(1)
// Space: O(1)

// bit manipulation
class Solution {
public:
    bool consecutiveSetBits(int n) {
        const auto& is_power_of_2 = [](int n) {
            return n > 0 && (n & (n - 1)) == 0;
        };

        return is_power_of_2(n & (n >> 1));
    }
};
