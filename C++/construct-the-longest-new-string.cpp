// Time:  O(1)
// Space: O(1)

// constructive algorithms, math
class Solution {
public:
    int longestString(int x, int y, int z) {
        return ((min(x, y) * 2 + static_cast<int>(x != y)) + z) * 2;
    }
};
