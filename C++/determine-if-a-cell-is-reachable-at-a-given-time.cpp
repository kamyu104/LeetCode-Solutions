// Time:  O(1)
// Space: O(1)

// constructive algorithms, math
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        const int diff1 = abs(sx - fx), diff2 = abs(sy - fy);
        const int mn = min(diff1, diff2) + abs(diff1 - diff2);
        return mn ? t >= mn : t != 1;
    }
};
