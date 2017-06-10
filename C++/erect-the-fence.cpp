// Time:  O(nlogn)
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
    vector<Point> outerTrees(vector<Point>& points) {
        const auto orientation = [](const Point& p, const Point& q, const Point& r) {
                                     return (q.y - p.y) * (r.x - q.x) - 
                                            (q.x - p.x) * (r.y - q.y);
                                 };
        const auto cmp = [](const Point& p, const Point& q) {
                             return p.x == q.x ? p.y < q.y : p.x < q.x;
                         };
        const auto eq = [](const Point &p1, const Point &p2) {
                            return p1.x == p2.x && p1.y == p2.y;
                        };

        vector<Point> hull;
        sort(points.begin(), points.end(), cmp);

        for (int i = 0; i < points.size(); ++i) {
            while (hull.size() >= 2 && 
                   orientation(hull[hull.size() - 2],
                               hull[hull.size() - 1],
                               points[i]) > 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }

        for (int i = points.size() - 1; i >= 0; --i) {
            while (hull.size() >= 2 && 
                   orientation(hull[hull.size() - 2],
                               hull[hull.size() - 1],
                               points[i]) > 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }

        sort(hull.begin(), hull.end(), cmp);
        hull.erase(unique(hull.begin(), hull.end(), eq), hull.end());
        return hull;
    }
};
