// Time:  O(1)
// Space: O(1)

// bit manipulation
class Solution {
public:
    long long maxNumber(long long n) {
        const auto& bit_length = [](auto x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        return (1ll << (bit_length(n) - 1)) - 1;
    }
};
