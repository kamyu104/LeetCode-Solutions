// Time:  O(nlogn)
// Space: O(n)

// sort, greedy
class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(begin(points), end(points), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        int result = 0;
        int left = -(w + 1);
        for (const auto& p : points) {
            if (p[0] - left <= w) {
                continue;
            }
            left = p[0];
            ++result;
        }
        return result;
    }
};
