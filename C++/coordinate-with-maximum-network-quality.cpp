// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int min_x = numeric_limits<int>::max();
        int max_x = numeric_limits<int>::min();
        int min_y = numeric_limits<int>::max();
        int max_y = numeric_limits<int>::min();
        for (const auto& tower: towers) {
            min_x = min(min_x, tower[0]);
            max_x = max(max_x, tower[0]);
            min_y = min(min_y, tower[1]);
            max_y = max(max_y, tower[1]);
        }
        int max_quality = 0;
        vector<int> result;
        for (int x = min_x; x <= max_x; ++x) {
            for (int y = min_y; y <= max_y; ++y) {
                int q = 0;
                for (const auto& t : towers) {
                    double d = sqrt((t[0] - x) * (t[0] - x) + (t[1] - y) * (t[1] - y));
                    if (d <= radius) {
                        q += int(t[2] / (1 + d));
                    }
                }
                if (q > max_quality) {
                    max_quality = q;
                    result = {x, y};
                }
            }
        }
        return result;
    }
};
