// Time:  O(s * log(m * n)), s is the max number of ships, which is 10 in this problem
// Space: O(log(m * n))

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int result = 0;
        if (topRight[0] >= bottomLeft[0] &&
            topRight[1] >= bottomLeft[1] &&
            sea.hasShips(topRight, bottomLeft)) {
            if (topRight == bottomLeft) {
                return 1;
            }
            const auto& mid_x = (topRight[0] + bottomLeft[0]) / 2;
            const auto& mid_y = (topRight[1] + bottomLeft[1]) / 2;
            result += countShips(sea, topRight, {mid_x + 1, mid_y + 1});
            result += countShips(sea, {mid_x, topRight[1]}, {bottomLeft[0], mid_y + 1});
            result += countShips(sea, {topRight[0], mid_y}, {mid_x + 1, bottomLeft[1]});
            result += countShips(sea, {mid_x, mid_y}, bottomLeft);
        }
        return result;
    }
};
