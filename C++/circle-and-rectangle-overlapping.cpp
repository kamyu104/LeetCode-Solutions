// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        x1 -= x_center;
        y1 -= y_center;
        x2 -= x_center;
        y2 -= y_center;
        const auto& x = (x1 > 0) ? x1 : (x2 < 0) ? x2 : 0;
        const auto& y = (y1 > 0) ? y1 : (y2 < 0) ? y2 : 0;
        return x * x + y * y <= radius * radius;
    }
};

// Time:  O(1)
// Space: O(1)
class Solution2 {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        x1 -= x_center;
        y1 -= y_center;
        x2 -= x_center;
        y2 -= y_center;
        const auto& x = (x1 * x2 > 0) ? min(abs(x1), abs(x2)) : 0;
        const auto& y = (y1 * y2 > 0) ? min(abs(y1), abs(y2)) : 0;
        return x * x + y * y <= radius * radius;
    }
};
