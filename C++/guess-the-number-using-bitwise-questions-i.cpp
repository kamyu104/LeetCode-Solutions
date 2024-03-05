// Time:  O(logn):
// Space: O(1)

// bit manipulation
class Solution {
public:
    int findNumber() {
        int result = 0;
        for (int i = 0; i < 30; ++i) {
            if (commonSetBits(1 << i)) {
                result |= 1 << i;
            }
        }
        return result;
    }
};
