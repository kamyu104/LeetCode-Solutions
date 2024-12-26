// Time:  O(nlogn)
// Space: O(1)

// sort, merge intervals
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        const auto& check = [&](int idx) {
            int cnt = 0;
            int curr = rectangles[0][idx + 2];
            for (const auto& x : rectangles) {
                cnt += curr <= x[idx] ? 1 : 0;
                curr = max(curr, x[idx + 2]);
            }
            return cnt >= 2;
        };

        for (int idx = 0; idx < 2; ++idx) {
            sort(begin(rectangles), end(rectangles), [&](const auto& a, const auto& b) {
                return a[idx] < b[idx];
            });
            if (check(idx)) {
                return true;
            }
        }
        return false;
    }
};
