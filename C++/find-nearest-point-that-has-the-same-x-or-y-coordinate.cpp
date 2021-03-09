// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int smallest = numeric_limits<int>::max();
        int idx = -1;
        for (int i = 0; i < size(points); ++i) {
            int dx = x - points[i][0], dy = y - points[i][1];
            if (dx * dy == 0 && abs(dx) + abs(dy) < smallest) {
                smallest = abs(dx) + abs(dy);
                idx = i;
            }
        }
        return idx;
    }
};
