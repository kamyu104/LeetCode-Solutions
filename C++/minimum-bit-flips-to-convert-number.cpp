// Time:  O(logn)
// Space: O(1)

// bit manipulation
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};
