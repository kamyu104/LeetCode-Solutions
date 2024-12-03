// Time:  O(1)
// Space: O(1)

// bit manipulation
class Solution {
public:
    int smallestNumber(int n) {
        const auto& bit_length = [](auto x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        return (1 << bit_length(n)) - 1;
    }
};
