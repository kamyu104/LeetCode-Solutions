// Time:  O(nlogn + m * max_y * logn), n = len(rectangles), m = len(points)
// Space: O(n)

// bucket sort, binary search
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        const auto max_y = (*max_element(cbegin(rectangles), cend(rectangles),
                                         [](const auto& a, const auto& b) {
                                             return a[1] < b[1];
                                         }))[1];
        vector<vector<int>> buckets(max_y + 1);
        for (const auto& rec : rectangles) {
            buckets[rec[1]].emplace_back(rec[0]);
        }
        for (auto& bucket : buckets) {
            sort(begin(bucket), end(bucket));
        }
        vector<int> result;
        for (const auto& p : points) {
            int cnt = 0;
            for (int y = p[1]; y <= max_y; ++y) {
                cnt += distance(lower_bound(cbegin(buckets[y]), cend(buckets[y]), p[0]), cend(buckets[y]));
            }
            result.emplace_back(cnt);
        }
        return result;
    }
};
