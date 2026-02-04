// Time:  O(logn)
// Space: O(1)

// bitmasks
class Solution {
public:
    int countMonobit(int n) {
        return bit_width(static_cast<uint32_t>(n + 1));
    }
};
