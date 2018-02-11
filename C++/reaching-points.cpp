// Time:  O(log(max(m, n)))
// Space: O(1)

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx < ty) {
                swap(sx, sy);
                swap(tx, ty);
            }
            if (ty > sy) {
                tx %= ty;
            } else {
                return (tx - sx) % ty == 0;
            }
        }
        return false;
    }
};
