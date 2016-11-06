// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) {
            return 0;
        }

        sort(points.begin(), points.end());

        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            int j = i + 1;
            int right_bound = points[i].second;
            while (j < points.size() && points[j].first <= right_bound) {
                right_bound = min(right_bound, points[j].second);
                ++j;
            }
            ++result;
            i = j - 1;
        }
        return result;
    }
};
