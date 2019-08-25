// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
	const auto& orientation = [](const vector<int>& p,
                                     const vector<int>& q,
                                     const vector<int>& r) {
                                         return (q[0] - p[0]) * (r[1] - p[1]) - 
                                                (q[1] - p[1]) * (r[0] - p[0]);
                                  };
        if (points.size() <= 1) {
            return points;
        }

        vector<vector<int>> hull;
        sort(points.begin(), points.end());
        for (int i = 0; i < points.size(); ++i) {
            while (hull.size() >= 2 && 
                   orientation(hull[hull.size() - 2],
                               hull[hull.size() - 1],
                               points[i]) < 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        for (int i = points.size() - 2; i >= 0; --i) {
            while (hull.size() >= 2 && 
                   orientation(hull[hull.size() - 2],
                               hull[hull.size() - 1],
                               points[i]) < 0) {
                hull.pop_back();
            }
            hull.emplace_back(points[i]);
        }
        hull.pop_back();

        for (int i = 1; i < (hull.size() + 1) / 2; ++i) {
            if (hull[i] != hull.back()) {
                break;
            }
            hull.pop_back();
        }
        return hull;
    }
};
