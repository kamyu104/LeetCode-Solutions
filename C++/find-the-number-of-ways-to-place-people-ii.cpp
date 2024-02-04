// Time:  O(n^2)
// Space: O(1)

// sort, array
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](const auto& a, const auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        int result = 0;
        for (int i = 0; i < size(points); ++i) {
            for (int j = i + 1, y = numeric_limits<int>::min(); j < size(points); ++j) {
                if (points[i][1] < points[j][1]) {
                    continue;
                }
                if (points[j][1] > y) {
                    y = points[j][1];
                    ++result;
                }
            }
        }
        return result;
    }
};

// Time:  O(n^3)
// Space: O(1)
// sort, array
class Solution2 {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](const auto& a, const auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        int result = 0;
        for (int i = 0; i < size(points); ++i) {
            for (int j = i + 1, y = numeric_limits<int>::min(); j < size(points); ++j) {
                if (points[i][1] < points[j][1]) {
                    continue;
                }
                bool valid = true;
                for (int k = i + 1; k < j; ++k) {
                    if (points[i][1] >= points[k][1] && points[k][1] >= points[j][1]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ++result;
                }
            }
        }
        return result;
    }
};
