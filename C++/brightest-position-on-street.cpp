// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        unordered_map<int, int> count;
        for (const auto& light : lights) {
            ++count[light[0] - light[1]];
            --count[light[0] + light[1] + 1];
        }
        vector<pair<int, int>> points;
        for (const auto& [k, v] : count) {
            points.emplace_back(k, v);
        }
        sort(begin(points), end(points));
        int result = numeric_limits<int>::min(), max_cnt = 0, cnt = 0;
        for (const auto& [i, c] : points) {
            cnt += c;
            if (cnt > max_cnt) {
                max_cnt = cnt;
                result = i;
            }
        }
        return result;
    }
};
