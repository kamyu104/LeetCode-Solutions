// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if (a == e && !(a == c && (b - d) * (f - d) < 0)) {
            return 1;
        }
        if (b == f && !(b == d && (a - c) * (e - c) < 0)) {
            return 1;
        }
        if (c + d == e + f && !(c + d == a + b && (c - a) * (e - a) < 0)) {
            return 1;
        }
        if (c - d == e - f && !(c - d == a - b && (d - b) * (f - b) < 0)) {
            return 1;
        }
        return 2;
    }
};
