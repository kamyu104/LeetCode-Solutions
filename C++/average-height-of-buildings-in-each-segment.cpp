// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
        vector<tuple<int, int, int>> points;
        for (const auto& b : buildings) {
            points.emplace_back(b[0], 1, b[2]);
            points.emplace_back(b[1], -1, b[2]);
        }
        sort(begin(points), end(points));
        vector<vector<int>> result;
        int total = 0, cnt = 0;
        int prev = -1;
        for (const auto& [curr, c, h] : points) {
            if (cnt && prev != curr) {
                if (!empty(result) && result.back()[1] == prev && result.back()[2] == total / cnt) {
                    result.back()[1] = curr;
                } else {
                    result.push_back({prev, curr, total / cnt});
                }
            }
            total += h * c;
            cnt += c;
            prev = curr;
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> count;
        for (const auto& b : buildings) {
            count[b[0]] =  {count[b[0]].first + 1, count[b[0]].second + b[2]};
            count[b[1]] =  {count[b[1]].first - 1, count[b[1]].second - b[2]};
        }
        vector<tuple<int, int, int>> points;
        for (const auto& [k, v] : count) {
            points.emplace_back(k, v.first, v.second);
        }
        sort(begin(points), end(points));
        vector<vector<int>> result;
        int total = 0, cnt = 0;
        int prev = -1;
        for (const auto& [curr, c, h] : points) {
            if (cnt) {
                if (!empty(result) && result.back()[1] == prev && result.back()[2] == total / cnt) {
                    result.back()[1] = curr;
                } else {
                    result.push_back({prev, curr, total / cnt});
                }
            }
            total += h;
            cnt += c;
            prev = curr;
        }
        return result;
    }
};
