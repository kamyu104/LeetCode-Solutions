// Time:  O(n^2 * logn)
// Space: O(n)

// angle sweep solution
// great explanation:
// https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/discuss/636345/Python-O(n3)-and-O(n2logn)-solution-explained-in-detail-with-pictures
class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            result = max(result, countPoints(points, r, i));
        }
        return result;
    }

private:
    int countPoints(const vector<vector<int>>& points, int r, int i) {
        vector<pair<double, bool>> angles;
        for (int j = 0; j < points.size(); ++j) {
            if (j == i) {
                continue;
            }
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            const auto d = sqrt(dx * dx + dy * dy);
            if (d > 2 * r) {
                continue;
            }
            const auto delta = acos(d / (2 * r));
            const auto angle = atan2(dy, dx);
            angles.emplace_back(angle - delta, false);
            angles.emplace_back(angle + delta, true);
        }
        sort(begin(angles), end(angles));
        int result = 1, count = 1;
        for (const auto& [_, is_closed] : angles) {  // angle sweep
            if (!is_closed) {
                ++count;
            } else {
                --count;
            }
            result = max(result, count);
        }
        return result;
    }
};
