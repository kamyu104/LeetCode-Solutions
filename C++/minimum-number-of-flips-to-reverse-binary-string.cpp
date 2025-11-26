// Time:  O(logn)
// Space: O(1)

// bitmasks
class Solution {
public:
    int minimumFlips(int n) {
        const auto& bit_length = [](int64_t x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const auto& l = bit_length(n);
        int result = 0;
        for (int i = 0; i < l / 2; ++i) {
            if (((n >> i) & 1) != (((n >> ((l - 1) - i)) & 1))) {
                result += 2;
            }
        }
        return result;
    }
};
