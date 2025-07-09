// Time:  O(logtx + logty)
// Space: O(1)

// backward simulation
class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        int result = 0;
        while (sx != tx || sy != ty) {
            if (!(sx <= tx && sy <= ty)) {
                return -1;
            }
            if (tx < ty) {
                if (tx > ty - tx) {
                    ty -= tx;
                } else {
                    if (ty % 2) {
                        return -1;
                    }
                    ty -= ty / 2;
                }
            } else if (tx > ty) {
                if (ty > tx - ty) {
                    tx -= ty;
                } else {
                    if (tx % 2) {
                        return -1;
                    }
                    tx -= tx / 2;
                }
            } else {
                if (sx == 0) {
                    tx -= ty;
                } else if (sy == 0) {
                    ty -= tx;
                } else {
                    return -1;
                }
            }
            ++result;
        }
        return result;
    }
};
