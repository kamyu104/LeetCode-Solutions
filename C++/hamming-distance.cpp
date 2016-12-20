// Time:  O(1)
// Space: O(1)

class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        for (int z = x ^ y; z; z &= z - 1) {
            ++distance;
        }
        return distance;
    }
};
