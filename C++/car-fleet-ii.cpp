// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<int> stk;
        vector<double> result(size(cars), -1.0);
        for (int i = size(cars) - 1; i >= 0; --i) {
            int p = cars[i][0], s = cars[i][1];
            while (!empty(stk) &&
                   (cars[stk.back()][1] >= s ||
                    (0 < result[stk.back()] &&
                     result[stk.back()] <= double(cars[stk.back()][0] - p) / (s - cars[stk.back()][1])))) {
                stk.pop_back();
            }
            if (!empty(stk)) {
                result[i] = double(cars[stk.back()][0] - p) / (s - cars[stk.back()][1]);
            }
            stk.emplace_back(i);
        }
        return result;
    }
};
