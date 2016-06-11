// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) {
            return true;
        }
        sort(points.begin(), points.end());
        sort(points.begin(), points.begin() + distance(points.begin(), points.end()) / 2,
            [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first == b.first) {
                    return a.second > b.second;
                }
                return a.first < b.first;
            });

        const auto mid = points.front().first + points.back().first;
        for (int left = 0, right = points.size() - 1; left <= right; ++left, --right) {
            if ((mid != points[left].first + points[right].first) || 
                (points[left].first != points[right].first &&
                 points[left].second != points[right].second)) {
                return false;
            }
        }
        return true;
    }
};
