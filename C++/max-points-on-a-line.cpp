// Time:  O(n^2)
// Space: O(n)

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int max_points = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> slope_count;
            const auto& start = points[i];
            int same = 1;

            for (int j = i + 1; j < points.size(); ++j) {
                const auto& end = points[j];
                if (start.x == end.x && start.y == end.y) {
                    ++same;
                } else {
                    auto slope = numeric_limits<double>::max();
                    if (start.x - end.x != 0) {
                        slope = (start.y - end.y) * 1.0 / (start.x - end.x);
                    }
                    ++slope_count[slope];
                }
            }

            int current_max = same;
            for (const auto& kvp : slope_count) {
                current_max = max(current_max, kvp.second + same);
            }
            max_points = max(max_points, current_max);
        }

        return max_points;
    }
};
