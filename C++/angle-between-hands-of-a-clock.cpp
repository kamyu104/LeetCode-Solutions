// Time:  O(1)
// Space: O(1)

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle1 = (hour % 12 * 60 + minutes) / 720.0;
        double angle2 = minutes / 60.0;
        double diff = abs(angle1 - angle2);
        return min(diff, 1.0 - diff) * 360.0;
    }
};
