// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> sorted_x;
        for (const auto& point : points) {
            sorted_x.emplace(point[0]);
        }
        int result = 0, prev = -1;
        for (const auto x : sorted_x) {
            if (prev != -1) {
                result = max(result, x - prev);
            }
            prev = x;
        }
        return result;
    }
};
