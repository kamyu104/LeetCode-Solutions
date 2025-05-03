// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(x - z) == abs(y - z) ? 0 : abs(x - z) < abs(y - z) ? 1 : 2;
    }
};
