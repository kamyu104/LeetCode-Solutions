// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        static const int USE = 5, REFILL = 1, DIST = 10;
        const int cnt = min((mainTank - REFILL) / (USE - REFILL), additionalTank);
        return (mainTank + cnt * REFILL) * DIST;
    }
};
